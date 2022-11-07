/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:21:53 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/06 03:16:49 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"


#if 0
void	tab_lock(t_rt *f)
{
	if (f->lock == 0)
	{
		f->lock = 1;
		f->img2 = mlx_new_image(f->mlx_id, 100, 100);
		int bpp = 0;
		int len = 0;
		int edn = 0;
		void *img2_adrr = mlx_get_data_addr(f->img2, &bpp, &len, &edn);

		for (int i = 0; i < 100; i++)
		{
			if (i % 2)
				continue;
			pixel(i, 0, LIME, img2_adrr, bpp, len);
			pixel(i, 99, LIME, img2_adrr, bpp, len);
			pixel(0, i, LIME, img2_adrr, bpp, len);
			pixel(99, i, LIME, img2_adrr, bpp, len);
		}
		mlx_put_image_to_window(f->mlx_id, f->win, f->img2, 100, 100);
		mlx_destroy_image(f->mlx_id, f->img2);
	}
	else
	{
		f->lock = 0;
		f->img2 = mlx_new_image(f->mlx_id, 100, 100);
		mlx_put_image_to_window(f->mlx_id, f->win, f->img2, 100, 100);
		mlx_destroy_image(f->mlx_id, f->img2);
	}
}

static void	hook_wcube_update(t_rt *f)
{
	if (!f->wcub.txt_buffer && !f->wcub.txt_buffer_old)
		return ;
	if (f->wcub.txt_buffer && f->wcub.txt_buffer_old)
	{
		if (0 == ft_strcmp(f->wcub.txt_buffer, f->wcub.txt_buffer_old))
			return ;
	}
	sc_cam_list_destroy(&f->cam);
	sc_shape_list_destroy(&f->ob);
	sc_light_list_destroy(&f->li);
	if (f->mlx.img[0].id)
		mlx_destroy_image(f->mlx.id, f->mlx.img[0].id);
	mlx_clear_window(f->mlx.id, f->mlx.win);
	f->mlx.img[0].id = mlx_new_image(f->mlx.id, f->mlx.win_x, f->mlx.win_y);
	if (!f->mlx.img[0].id)
		rt_exit(f, 33, "mlx_new_image() failed");

	the_return(f);
	raytracing_each_pixel(f);
	mlx_put_image_to_window(f->mlx.id, f->mlx.win, f->mlx.img[0].id, 0, 0);
	if (f->wcub.txt_buffer)
	{
		if (f->wcub.txt_buffer_old)
		{
			free(f->wcub.txt_buffer_old);
			f->wcub.txt_buffer_old = ft_strdup(f->wcub.txt_buffer);
		}
		free(f->wcub.txt_buffer);
		f->wcub.txt_buffer = NULL;
	}
}

static void	hook_wcube_add_char(int keycode, t_rt *f)
{
	char	*new;

	if (f->wcub.txt_buffer)
	{
		new = ft_strjoin(f->wcub.txt_buffer, ".");
		free(f->wcub.txt_buffer);
	}
	else
		new = ft_strdup(".");
	new[ft_strlen(new) - 1] = keycode;
	f->wcub.txt_buffer = new;
}

#define ESCAPE	65307
#define ENTER	65293
#define TAB		65289

int	key_press(int keycode, t_rt *f)
{
	if (keycode == ESCAPE)
		rt_exit(f, EXIT_SUCCESS, "exit_escape");
	// if (keycode == TAB) //tmp
		// tab_lock(f);
	if (MRT_PUTS_MODE == 0)
		return (0);
	if (ft_isalnum(keycode) || keycode == ' ')
		hook_wcube_add_char(keycode, f);
	if (keycode == ENTER)
		hook_wcube_update(f);
	return (0);
}

int	exit_cross(t_rt *f)
{
	rt_exit(f, EXIT_SUCCESS, "exit_cross");
	return (0);
}

#endif
