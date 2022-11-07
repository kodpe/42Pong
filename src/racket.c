/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   racket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:43:38 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/06 19:40:48 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void	update_racket(t_m *m, t_racket *r)
{
	smlx_hline(&m->mlx.img[0], smlx_pos(r->x, r->y), r->x_size, r->color);
}

static void	receive_ball(t_m *m, char *line)
{
	int	bxy;

	bxy = ft_atoi(line + 2);
	m->ball.x = m->g_max.x - bxy / 10000;
	m->ball.y = m->g_max.y - bxy % 10000;
}

void	receive(t_m *m)
{
	int		fd;
	char	*line;

	fd = open(m->opponent, O_RDONLY, O_CLOEXEC);
	if (fd == -1)
		pong_exit(m);
	line = get_next_line(fd);
	if (line)
	{
		if (line[0] == 'R' && line[1] == 'L')
			m->r1.x += m->r1.x_pad;
		if (line[0] == 'R' && line[1] == 'R')
			m->r1.x -= m->r1.x_pad;
		if (line[0] == 'b')
			receive_ball(m, line);
		free(line);
	}
	ft_close_gnl(fd);
	close(fd);
	fd = open(m->opponent, O_WRONLY | O_TRUNC | O_CLOEXEC);
	if (fd == -1)
		pong_exit(m);
	close(fd);
}

void	send(t_m *m, char *msg)
{
	int	fd;

	fd = open(m->player, O_WRONLY | O_TRUNC | O_CLOEXEC);
	if (fd == -1)
		pong_exit(m);
	ft_putstr_fd(msg, fd);
	close(fd);
}
