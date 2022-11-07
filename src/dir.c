/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:24:26 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/06 15:12:18 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void	dir_log(char *dirpath)
{
	DIR				*d;
	struct dirent	*dir;
	int				n;
	char			*cwd;

	dprintf(2, "input  : [%s]\n", dirpath);
	d = opendir(dirpath);
	if (!d)
	{
		perror("dir_log");
		abort();
	}
	cwd = getcwd(NULL, 0);
	dprintf(2, "getcwd : [%s]\n", cwd);
	free(cwd);
	n = 0;
	while (1)
	{
		dir = readdir(d);
		if (dir == NULL)
			break ;
		dprintf(2, "%7d: [%s]\n", n, dir->d_name);
		n++;
	}
	closedir(d);
}

// without dots
int	dir_size(char *dirpath)
{
	DIR				*d;
	struct dirent	*dir;
	int				n;

	d = opendir(dirpath);
	if (!d)
	{
		perror("dir_size");
		abort();
	}
	n = 0;
	while (1)
	{
		dir = readdir(d);
		if (dir == NULL)
			break ;
		n++;
	}
	closedir(d);
	return (n - 2);
}

// without dots
char	**dir_namelist(char *dirpath)
{
	DIR				*d;
	struct dirent	*dir;
	char			**list;
	int				size;
	int				i;

	size = dir_size(dirpath);
	if (!size)
		return (NULL);
	list = malloc(sizeof(char *) * (size + 1));
	if (!list)
		abort();
	d = opendir(dirpath);
	if (!d)
		abort();
	i = 0;
	while (1)
	{
		dir = readdir(d);
		if (dir == NULL)
			break ;
		if (dir->d_name[0] != '.')
		{
			list[i] = ft_strdup(dir->d_name);
			i++;
		}
	}
	list[i] = NULL;
	closedir(d);
	return (list);
}
