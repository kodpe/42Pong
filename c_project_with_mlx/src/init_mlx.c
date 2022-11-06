/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:42:29 by sloquet           #+#    #+#             */
/*   Updated: 2022/09/17 02:48:35 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "name.h"

// 1503-1337
static void	struct_init(t_rt *f)
{
	f->mlx_id = NULL;
	f->win = NULL;
	f->img_id = NULL;
	f->img_addr = NULL;
	f->img_endian = 0;
	f->bits_per_pixel = 0;
	f->line_length = 0;
	f->win_x = 2112;
	f->win_y = 1056;
	f->center.x = f->win_x / 2;
	f->center.y = f->win_y / 2;
}

// 1503-1317
static void	smlx_init(t_rt *f)
{
	f->mlx_id = mlx_init();
	if (!f->mlx_id)
		rt_destroy(f, 31, "mlx_init() failed");
}

// 1503-1337
static void	smlx_new_window(t_rt *f)
{
	f->win = mlx_new_window(f->mlx_id, f->win_x, f->win_y, "FdF");
	if (!f->win)
		rt_destroy(f, 32, "mlx_new_window() failed");
}

// 1503-1435
static void	smlx_new_image(t_rt *f)
{
	f->img_id = mlx_new_image(f->mlx_id, f->win_x, f->win_y);
	if (!f->img_id)
		rt_destroy(f, 33, "mlx_new_image() failed");
	f->img_addr = mlx_get_data_addr(f->img_id, &f->bits_per_pixel, \
		&f->line_length, &f->img_endian);
	if (!f->img_addr)
		rt_destroy(f, 34, "mlx_get_data_addr() failed");
}

// 1703-1928
void	rt_init_mlx(t_rt *f, int ac)
{
	if (ac != 2)
		error_exit(30, "invalid arg");
	struct_init(f);
	smlx_init(f);
	smlx_new_window(f);
	smlx_new_image(f);
}
