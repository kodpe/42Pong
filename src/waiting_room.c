/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:33:21 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/06 14:15:2 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

static int	exit_cross_st(t_m *m)
{
	pong_exit(m);
	return (0);
}

static int	key_press_st(int keycode, t_m *m)
{
	if (keycode == KEY_ESCAPE)
		pong_exit(m);
	return (0);
}

static void	display_waiting_room(t_m *m)
{
	ball(m, m->mlx.win.width / 2 - 15 + m->i, \
	m->mlx.win.height / 2);
	smlx_display_image(&m->mlx, 0, 0, 0);
	mlx_string_put(m->mlx.ptr, m->mlx.win.ptr, \
		m->mlx.win.width / 2 - 65, \
		m->mlx.win.height / 2 - 20, \
		WHITE, PONG_STR_WAIT);
}

static int	loop_chrono_st(t_m *m)
{
	char	**namelist;

	usleep(200000);
	if (smlx_reset_image(&m->mlx, 0))
		pong_exit(m);
	display_waiting_room(m);
	m->i += 10;
	if (m->i == 30)
		m->i = 0;
	if (dir_size(".") == 2)
	{
		namelist = dir_namelist(".");
		assert(namelist);
		if (ft_strcmp(m->player, namelist[0]))
			m->opponent = ft_strdup(namelist[0]);
		else
			m->opponent = ft_strdup(namelist[1]);
		ft_arfree(namelist);
		mlx_loop_end(m->mlx.ptr);
	}
	return (0);
}

void	waiting_room(t_m *m)
{
	mlx_loop_hook(m->mlx.ptr, &loop_chrono_st, m);
	mlx_hook(m->mlx.win.ptr, 2, 1L << 0, &key_press_st, m);
	mlx_hook(m->mlx.win.ptr, 17, 0, &exit_cross_st, m);
	mlx_loop(m->mlx.ptr);
}
