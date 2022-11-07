/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:41:55 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/06 19:42:19 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

static double	get_ball_angle(void)
{
	double	v;

	v = 1.0 / (rand() % 3 + 1);
	if (rand() % 2)
		v = -v;
	return (v);
}

static void	ball_collision_box(t_m *m)
{
	t_ball	*b;
	int		edge;

	b = &m->ball;
	if (m->box.persistance == 0)
		m->box.color = m->box.color_default;
	else
		m->box.persistance--;
	edge = m->box.border + 2;
	if (b->x + b->x_pad > m->g_max.x - edge || b->x + b->x_pad < edge)
	{
		b->x_pad = -b->x_pad;
		m->box.color = m->box.color_touch;
		m->box.persistance = m->box.persistance_time;
	}
	if (b->y + b->y_pad > m->g_max.y - edge || b->y + b->y_pad < edge)
	{
		if (b->y + b->y_pad > m->g_max.y - edge)
			m->r1.score++;
		if (b->y + b->y_pad < edge)
			m->r2.score++;
		b->y_pad = -b->y_pad;
		m->box.color = m->box.color_touch;
		m->box.persistance = m->box.persistance_time;
	}
}

static void	ball_collision_rackets(t_m *m)
{
	t_ball	*b;

	b = &m->ball;

	if (b->y + b->y_pad > m->r2.y - 2 \
		&& b->x >= m->r2.x && b->x < m->r2.x + m->r2.x_size)
	{
		b->y_pad = -b->y_pad;
		b->x_pad = get_ball_angle();
	}
	if (b->y + b->y_pad < m->r1.y + 2 \
		&& b->x >= m->r1.x && b->x < m->r1.x + m->r1.x_size)
	{
		b->y_pad = -b->y_pad;
		b->x_pad = get_ball_angle();
	}
}

static void	sc_check_outwindow(t_m *m)
{
	t_ball	*b;
	int		edge;

	b = &m->ball;
	edge = m->box.border + 2;
	if (b->x > m->g_max.x - edge || b->x < edge)
	{
		b->x = m->g_center.x;
		b->y = m->g_center.y;
	}
	else if (b->y > m->g_max.y - edge || b->y < edge)
	{
		b->x = m->g_center.x;
		b->y = m->g_center.y;
	}
}

void	ball(t_m *m, int x, int y)
{
	t_img	*img;
	int		color;

	img = &m->mlx.img[0];
	color = m->ball.color;
	smlx_pixel(img, x, y, color);
	smlx_pixel(img, x - 1, y, color);
	smlx_pixel(img, x + 1, y, color);
	smlx_pixel(img, x, y - 1, color);
	smlx_pixel(img, x, y + 1, color);
}

void	update_ball(t_m *m)
{
	if (m->server)
	{
		ball_collision_box(m);
		ball_collision_rackets(m);
		m->ball.x += m->ball.x_pad;
		m->ball.y += m->ball.y_pad;

		int	bxy = m->ball.x * 10000 + m->ball.y;
		char	*s = ft_itoa(bxy);
		char	*msg = ft_strjoin("b ", s);
		send(m, msg);
		free(s);
		free(msg);
	}
	sc_check_outwindow(m);
	ball(m, m->ball.x, m->ball.y);
}
