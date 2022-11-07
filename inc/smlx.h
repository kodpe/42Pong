/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:06:56 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/06 18:17:43 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMLX_H
# define SMLX_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define SMLX_WIN_SIZE_X 500
# define SMLX_WIN_SIZE_Y 500
# define SMLX_WIN_NAME "42Pong"

typedef struct s_2Dpnt
{
	int	x;
	int	y;
}	t_2Dpnt;

typedef struct s_img
{
	int		id;
	int		height;
	int		width;
	char	*title;
	void	*ptr;
	void	*addr;
	int		bpp;
	int		len;
	int		end;
}	t_img;
// (end endian) (len line_length) (bpp bits_per_pixel)

typedef struct s_win
{
	int		id;
	int		height;
	int		width;
	char	*title;
	void	*ptr;
}	t_win;

typedef struct s_smlx
{
	void	*ptr;
	t_win	win;
	t_img	*img;
	int		nb_img;
}	t_smlx;

void	smlx_pixel(t_img *img, int x, int y, int hex_color);
int		smlx_new_xpm(t_smlx *mlx, t_img *img, char *file, int id);
int		smlx_new_image(t_smlx *mlx, int id, int width, int height);
int		smlx_new_window(t_smlx *mlx, int id, int width, int height);
int		smlx_init(t_smlx *mlx, int nb_img);
int		smlx_reload(t_smlx *mlx, int nb_img);
void	smlx_destroy_image(t_smlx *mlx, t_img *img);
void	smlx_destroy(t_smlx *mlx);
void	smlx_display_image(t_smlx *mlx, int id, int x, int y);
int		smlx_reset_image(t_smlx *mlx, int id);
t_2Dpnt	smlx_pos(int x, int y);
void	smlx_box_img(t_img *img, t_2Dpnt origin, int hexcolor);
void	smlx_box_max(t_img *img, t_2Dpnt origin, t_2Dpnt max, int hexcolor);
void	smlx_box_len(t_img *img, t_2Dpnt origin, t_2Dpnt len, int hexcolor);
void	smlx_hline(t_img *img, t_2Dpnt origin, int len, int hexcolor);

#endif
