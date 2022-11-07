/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:50:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/11/06 13:3 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void	pong_exit(t_m *m)
{
	LOG
	if (m->mlx.ptr)
		smlx_destroy(&m->mlx);
	if (m->player)
		unlink(m->player);
	free(m->player);
	free(m->opponent);
	free(m->name_player);
	free(m->name_opponent);
	exit(0);
}

void	game_init_specs(t_m *m)
{
	m->box.color_default = WHITE;
	m->box.color = WHITE;
	m->box.color_touch = LIME;
	m->box.persistance = 0;
	m->box.persistance_time = 50;
	m->box.border = 20;

	m->g_max.x = SMLX_WIN_SIZE_X;
	m->g_max.y = SMLX_WIN_SIZE_Y;
	m->g_center.x = m->g_max.x / 2;
	m->g_center.y = m->g_max.y / 2;

	m->ball.color = WHITE;
	m->ball.x = m->g_center.x;
	m->ball.y = m->g_center.y;
	if (rand() % 2)
		m->ball.y_pad = 0.5;
	else
		m->ball.y_pad = -0.5;
	m->ball.x_pad = 0;

	m->g_racket_size = 100;
	m->g_racket_pad = 10;
	m->g_racket_color = WHITE;

	m->r1.x_size = m->g_racket_size;
	m->r1.x_pad = m->g_racket_pad;
	m->r1.color = m->g_racket_color;
	m->r1.x = m->g_center.x - (m->r1.x_size / 2);
	m->r1.y = m->box.border + 20;

	m->r2.x_size = m->g_racket_size;
	m->r2.x_pad = m->g_racket_pad;
	m->r2.color = m->g_racket_color;
	m->r2.x = m->g_center.x - (m->r2.x_size / 2);
	m->r2.y = m->g_max.y - (m->box.border + 20);
}

void	log_data(t_m *m)
{
	dprintf(2, "GAME %s VS %s\n", m->player, m->opponent);
	dprintf(2, "PLAYER_NAME    : [%s]\n", m->name_player);
	dprintf(2, "PLAYER_FCODE   : [%s]\n", m->player);
	dprintf(2, "OPONNENT_NAME  : [%s]\n", m->name_opponent);
	dprintf(2, "OPONNENT_FCODE : [%s]\n", m->opponent);
	if (m->server)
		dprintf(2, "server : %s\nclient : %s\n", m->player, m->opponent);
	else
		dprintf(2, "server : %s\nclient : %s\n", m->opponent, m->player);
}

int	main(void)
{
	t_m	m;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	ft_memset(&m, 0, sizeof(t_m));
	srand(time(&m.t));
	game_init_specs(&m);
	if (server_exist())
		create_client(&m);
	else
		create_server(&m);
	log_data(&m);
	game_room(&m);
	pong_exit(&m);
	return (1);
}
