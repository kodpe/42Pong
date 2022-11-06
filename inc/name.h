/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:26:11 by sloquet           #+#    #+#             */
/*   Updated: 2022/09/17 03:11:05 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_H
# define NAME_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
// # include <sys/ioctl.h>
// # include <readline/readline.h>
// # include <readline/history.h>
// # include <sys/types.h>
// # include <sys/wait.h>
// # include <sys/stat.h>
// # include <fcntl.h>
// # include <stdbool.h>
// # include <errno.h>
// # include <dirent.h>
// # include <signal.h>
// # include <limits.h>

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "name_types.h"

# define SUCCESS		0
# define FAILURE		1
# define ERR_MALLOC		-1

/** DEBUG OPTIONS **/
# define LOG		c_magenta();\
					printf("%s:%d %s()\n", __FILE__,__LINE__, __FUNCTION__);\
					c_reset();
# define TEST_X 	0
# define SHOW_X 	0

/**
 * 		init_mlx.c
 */
void	rt_init_mlx(t_rt *f, int ac);

/**
 * 		utils.c
 */
int		distance_cart(int x0, int y0, int x1, int y1);

/**
 * 		destroy.c
 */
int		error_exit(int code, char *msg);
int		rt_destroy(t_rt *f, int code, char *msg);

#endif /* NAME_H */
