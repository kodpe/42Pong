/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:49:25 by sloquet           #+#    #+#             */
/*   Updated: 2022/09/17 03:16:28 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "name.h"

// 1903-2004
int	error_exit(int code, char *msg)
{
	LOG

	ft_printf("\033[0;33mERR %d : %s\033[0m\n", code, msg);
	exit (code);
}

int	rt_destroy(t_rt *f, int code, char *msg)
{
	LOG

	if (f->img_id)
		mlx_destroy_image(f->mlx_id, f->img_id);
	if (f->win)
		mlx_destroy_window(f->mlx_id, f->win);
	if (f->mlx_id)
		mlx_destroy_display(f->mlx_id);
	free(f->mlx_id);
	if (code > 30)
		error_exit(code, msg);
	exit(code);
}
