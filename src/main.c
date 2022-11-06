/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:50:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/09/17 03:15:09 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "name.h"

// 1503-1551
int	exit_cross(t_rt *f)
{
	LOG

	rt_destroy(f, 0, "exit_cross");
	return (0);
}

// 1503-1552
int	key_press(int keycode, t_rt *f)
{
	LOG

	ft_printf("key_press()         : %d\n", keycode);
	if (keycode == 0xff1b)
		rt_destroy(f, 0, "exit_escape");
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_rt	f;

	LOG

	rt_init_mlx(&f, ac);
	//TODO PARSING
	//TODO RAYTRACING
	//TODO FREE ALL
	mlx_put_image_to_window(f.mlx_id, f.win, f.img_id, 0, 0);
	mlx_hook(f.win, 2, 1L << 0, &key_press, &f);
	mlx_hook(f.win, 17, 0, &exit_cross, &f);
	mlx_loop(f.mlx_id);
	rt_destroy(&f, 36, "invalid exit");
	return (0);
	(void)av;
	(void)ac;
	(void)envp;
}
