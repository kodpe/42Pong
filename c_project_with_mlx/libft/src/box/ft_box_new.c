/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:08:21 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 13:58:46 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_box.h"

static char	*box_malloc_x(int x)
{
	char	*line;
	int		ix;

	line = (char *)malloc(sizeof(char) * (x + 1));
	if (!line)
		return (NULL);
	line[x] = 0;
	ix = 0;
	while (ix < x)
	{
		line[ix] = 42;
		ix++;
	}
	return (line);
}

static char	**box_malloc_y(int y, int x)
{
	char	**array;
	int		iy;

	array = (char **)malloc(sizeof(char *) * (y + 1));
	if (array)
		return (NULL);
	array[y] = NULL;
	iy = 0;
	while (iy < y)
	{
		array[iy] = box_malloc_x(x);
		if (!array[iy])
		{
			while (--iy)
				free(array[iy]);
			free(array);
			return (NULL);
		}
		iy++;
	}
	return (array);
}

static void	boxdel(char **array, int y)
{
	while (y)
	{
		free(array[y]);
		y--;
	}
	free(array);
}

char	***ft_box_new(const int x, const int y, const int z)
{
	char	***box;
	int		iz;

	box = (char ***)malloc(sizeof(char **) * (z + 1));
	if (!box)
		return (NULL);
	box[z] = NULL;
	iz = 0;
	while (iz < z)
	{
		box[iz] = box_malloc_y(y, x);
		if (!box[iz])
		{
			while (--iz)
				boxdel(box[iz], y);
			free(box[iz]);
			return (NULL);
		}
		iz++;
	}
	return (box);
}
