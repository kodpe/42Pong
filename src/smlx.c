/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:39:42 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/06 18:17:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smlx.h"

void	smlx_pixel(t_img *img, int x, int y, int hex_color)
{
	char			*dest;
	int				offset;
	unsigned int	color;

	color = hex_color;
	offset = y * img->len + x * (img->bpp / 8);
	dest = img->addr + offset;
	*(unsigned int *)dest = color;
}

int	smlx_new_xpm(t_smlx *mlx, t_img *img, char *file, int id)
{
	img->id = id;
	img->title = ft_strdup(file);
	if (!img->title)
		return (1);
	img->ptr = mlx_xpm_file_to_image(mlx->ptr, file, &img->width, &img->height);
	if (!img->ptr)
		return (1);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->len, &img->end);
	if (!img->addr)
		return (1);
	return (0);
}

int	smlx_new_image(t_smlx *mlx, int id, int width, int height)
{
	t_img	*img;

	img = &mlx->img[id];
	img->id = id;
	img->width = width;
	img->height = height;
	if (width < 1 || height < 1)
		return (1);
	img->title = ft_itoa(img->id);
	if (!img->title)
		return (1);
	img->ptr = mlx_new_image(mlx->ptr, img->width, img->height);
	if (!img->ptr)
		return (1);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->len, &img->end);
	if (!img->addr)
		return (1);
	return (0);
}

#ifndef SMLX_WIN_SIZE_X
# define SMLX_WIN_SIZE_X 800
#endif

#ifndef SMLX_WIN_SIZE_Y
# define SMLX_WIN_SIZE_Y 600
#endif

#ifndef SMLX_WIN_NAME
# define SMLX_WIN_NAME "undefine WIN_TITLE"
#endif

int	smlx_new_window(t_smlx *mlx, int id, int width, int height)
{
	t_win	*win;

	win = &mlx->win;
	win->id = id;
	win->width = width;
	win->height = height;
	if (width < 100 || height < 100)
		return (1);
	win->ptr = mlx_new_window(mlx->ptr, win->width, win->height, SMLX_WIN_NAME);
	if (!win->ptr)
		return (1);
	return (0);
}

int	smlx_reload(t_smlx *mlx, int nb_img)
{
	smlx_destroy(mlx);
	if (smlx_init(mlx, nb_img))
		return (smlx_destroy(mlx), 1);
	return (0);
}

int	smlx_init(t_smlx *mlx, int nb_img)
{
	int	i;

	ft_memset(mlx, 0, sizeof(t_smlx));
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (1);
	if (smlx_new_window(mlx, 0, SMLX_WIN_SIZE_X, SMLX_WIN_SIZE_Y))
		return (1);
	mlx->nb_img = nb_img;
	if (mlx->nb_img < 1)
		return (1);
	mlx->img = ft_calloc(sizeof(t_img) * mlx->nb_img);
	if (!mlx->img)
		return (1);
	i = 0;
	while (i < mlx->nb_img)
	{
		if (smlx_new_image(mlx, i, SMLX_WIN_SIZE_X, SMLX_WIN_SIZE_Y))
			return (1);
		i++;
	}
	return (0);
}

void	smlx_destroy_image(t_smlx *mlx, t_img *img)
{
	if (img)
	{
		if (img->ptr)
		{
			mlx_destroy_image(mlx->ptr, img->ptr);
			img->ptr = NULL;
		}
		free(img->title);
		img->title = NULL;
	}
}

void	smlx_destroy(t_smlx *mlx)
{
	int	i;

	i = 0;
	if (mlx->img)
	{
		while (i < mlx->nb_img)
		{
			smlx_destroy_image(mlx, &mlx->img[i]);
			i++;
		}
		free(mlx->img);
		mlx->nb_img = 0;
		mlx->img = NULL;
	}
	if (mlx->win.ptr)
	{
		mlx_destroy_window(mlx->ptr, mlx->win.ptr);
		mlx->win.ptr = NULL;
	}
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		mlx->ptr = NULL;
	}
}

void	smlx_display_image(t_smlx *mlx, int id, int x, int y)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win.ptr, mlx->img[id].ptr, x, y);
}

int	smlx_reset_image(t_smlx *mlx, int id)
{
	int	width;
	int	height;

	width = mlx->img[id].width;
	height = mlx->img[id].height;
	smlx_destroy_image(mlx, &mlx->img[id]);
	if (smlx_new_image(mlx, id, width, height))
		return (1);
	return (0);
}

void	smlx_box_img(t_img *img, t_2Dpnt origin, int hexcolor)
{
	for (int i = origin.x; i < img->width; i++)
	{
		smlx_pixel(img, i, origin.y, hexcolor);
		smlx_pixel(img, i, img->height - 1, hexcolor);
	}
	for (int i = origin.y; i < img->height; i++)
	{
		smlx_pixel(img, origin.x, i, hexcolor);
		smlx_pixel(img, img->width - 1, i, hexcolor);
	}
}

t_2Dpnt	smlx_pos(int x, int y)
{
	t_2Dpnt	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

void	smlx_box_max(t_img *img, t_2Dpnt origin, t_2Dpnt max, int hexcolor)
{
	for (int i = origin.x; i <= max.x; i++)
	{
		smlx_pixel(img, i, origin.y, hexcolor);
		smlx_pixel(img, i, max.y, hexcolor);
	}
	for (int i = origin.y; i <= max.y; i++)
	{
		smlx_pixel(img, origin.x, i, hexcolor);
		smlx_pixel(img, max.x, i, hexcolor);
	}
}

void	smlx_box_len(t_img *img, t_2Dpnt origin, t_2Dpnt len, int hexcolor)
{
	for (int i = origin.x; i < origin.x + len.x; i++)
	{
		smlx_pixel(img, i, origin.y, hexcolor);
		smlx_pixel(img, i, origin.y + len.y - 1, hexcolor);
	}
	for (int i = origin.y; i < origin.y + len.y; i++)
	{
		smlx_pixel(img, origin.x, i, hexcolor);
		smlx_pixel(img, origin.x + len.x - 1, i, hexcolor);
	}
}

void	smlx_hline(t_img *img, t_2Dpnt origin, int len, int hexcolor)
{
	int	i;

	i = 0;
	while (i < len)
	{
		smlx_pixel(img, origin.x + i, origin.y, hexcolor);
		i++;
	}
}
