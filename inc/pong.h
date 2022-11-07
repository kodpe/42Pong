/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:26:11 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/06 18:46:58 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONG_H
# define PONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
// # include <math.h>
# include <time.h>
# include <sys/types.h>
# include <stdbool.h>
# include <dirent.h>
# include <assert.h>
# include <signal.h>
// # include <sys/ioctl.h>
// # include <sys/wait.h>
// # include <sys/stat.h>
// # include <fcntl.h>
// # include <errno.h>
// # include <limits.h>

# include "../libft/libft.h"
# include "smlx.h"
# include "colors.h"

# define SUCCESS		0
# define FAILURE		1
# define ERR_MALLOC		-1

/** DEBUG OPTIONS **/
# define LOG		c_magenta();\
					printf("%s:%d %s()\n", __FILE__,__LINE__, __FUNCTION__);\
					c_reset();

# define PONG_DATA_PATH "/home/sylvain/Documents/42Pong/data"	
# define PONG_PHOTO_PATH "/home/sylvain/Documents/42Pong/data_photo/"	

# define PONG_STR_START	"Game will start in  s"
# define PONG_STR_WAIT	"Waiting for an opponent"

#define KEY_ESCAPE 65307

#define KEY_LEFT	65361
#define KEY_UP		65362
#define KEY_RIGHT	65363
#define KEY_DOWN	65364
#define KEY_A		97
#define KEY_D		100

typedef struct s_racket
{
	int	x;
	int	y;
	int	x_pad;
	int	x_size;
	int	score;
	int	color;
}	t_racket;

typedef struct s_ball
{
	double	x;
	double	y;
	double	x_pad;
	double	y_pad;
	int		color;
}	t_ball;

typedef struct s_box
{
	int			color_default;
	int			color_touch;
	int			color;
	int			persistance;
	int			persistance_time;
	int			border;
}	t_box;

typedef struct s_m
{
	t_smlx		mlx;
	time_t		t;
	t_box		box;
	t_ball		ball;
	t_racket	r1;
	t_racket	r2;

	t_2Dpnt		g_max;
	t_2Dpnt		g_center;
	int			g_racket_size;
	int			g_racket_pad;
	int			g_racket_color;

	bool		server;
	bool		client;
	int			i;
	int			starting_delay;

	char		*player;
	char		*opponent;
	char		*name_player;
	char		*name_opponent;
}	t_m;

void	dir_log(char *dirpath);
int		dir_size(char *dirpath);
char	**dir_namelist(char *dirpath);

void	pong_exit(t_m *m);

int		server_exist(void);
void	create_server(t_m *m);
void	create_client(t_m *m);

void	waiting_room(t_m *m);
void	starting_room(t_m *m);
void	game_room(t_m *m);

void	ball(t_m *m, int x, int y);
void	update_ball(t_m *m);

void	racket(t_m *m, int size, int x, int y);
void	update_racket(t_m *m, t_racket *r);

void	send(t_m *m, char *msg);
void	receive(t_m *m);
#endif /* PONG_H */
