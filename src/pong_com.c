/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:12:43 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/06 15:31:23 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

static void	pong_create_name(t_m *m)
{
	char	*num;
	char	*file;
	int		fd;

	num = ft_itoa(rand() % 90 + 10 + (rand() % 90 + 10) * 1000);
	file = ft_strjointri(getenv("USER"), "_", num);
	free(num);
	m->player = file;

	fd = open(file, O_CREAT | O_RDONLY | O_TRUNC, 0644);
	if (fd == -1)
		abort();
	close(fd);

	assert(m->player);
	int	i;
	i = 0;
	while (m->player[i])
	{
		if (m->player[i] == '_')
			break ;
		i++;
	}
	m->name_player = ft_strldup(m->player, i + 1);
}

int	server_exist(void)
{
	char	**namelist;

	if (chdir(PONG_DATA_PATH))
		abort();
	// dir_log(".");
	if (dir_size(".") > 1)
	{
		dprintf(2, "ERROR com dir broken\n");
		abort();
	}
	namelist = dir_namelist(".");
	if (!namelist)
		return (0);
	ft_arfree(namelist);
	return (1);
}

void	create_server(t_m *m)
{
	dprintf(2, "CREATE GAME / WAITING FOR OPPONENT\n");
	pong_create_name(m);
	m->server = 1;
	m->client = 0;
	if (smlx_init(&m->mlx, 1))
		pong_exit(m);
	waiting_room(m);

	assert(m->opponent);
	int i;
	i = 0;
	while (m->opponent[i])
	{
		if (m->opponent[i] == '_')
			break ;
		i++;
	}
	m->name_opponent = ft_strldup(m->opponent, i + 1);

	if (smlx_reload(&m->mlx, 1))
		pong_exit(m);
	starting_room(m);
	if (smlx_reload(&m->mlx, 1))
		pong_exit(m);
}

void	create_client(t_m *m)
{
	char	**namelist;

	namelist = dir_namelist(".");
	if (!namelist)
		pong_exit(m);
	m->server = 0;
	m->client = 1;
	m->opponent = ft_strdup(namelist[0]);
	ft_arfree(namelist);

	assert(m->opponent);
	int i;
	i = 0;
	while (m->opponent[i])
	{
		if (m->opponent[i] == '_')
			break ;
		i++;
	}
	m->name_opponent = ft_strldup(m->opponent, i + 1);

	pong_create_name(m);
	dprintf(2, "JOIN GAME with opponent : [%s]\n", m->opponent);
	if (smlx_init(&m->mlx, 1))
		pong_exit(m);
	starting_room(m);
	if (smlx_reload(&m->mlx, 1))
		pong_exit(m);
}
