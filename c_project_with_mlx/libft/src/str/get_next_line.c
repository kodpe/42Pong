/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:10:49 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/21 17:45:18 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#define FD_MAX 1024

/**
 * GET_NEXT_LINE
 * 
 * PARAMETERS 			: File descriptor (fd) to read from
 * 
 * RETURN VALUE 		: Read line : correct behavior
 * 						  null      : nothing else to read or an error occurred
 * 
 * EXTERNAL FUNCTIONS	: read, malloc, free
 * 
 * DESCRIPTION			: Returns a line read from a file descriptor
 */

static int	ft_read(int fd, char **buff, char **save)
{
	int		nbytes;
	char	*tmp;

	nbytes = 1;
	while (nbytes && !ft_strchr(*save, '\n'))
	{
		nbytes = read(fd, *buff, BUFFER_SIZE);
		if (nbytes == -1)
			return (-1);
		(*buff)[nbytes] = 0;
		tmp = *save;
		*save = ft_strjoin(tmp, *buff);
		free(tmp);
		tmp = NULL;
	}
	return (nbytes);
}

static char	*ft_pull(char **save)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	tmp = *save;
	*save = ft_strdup(&(*save)[i + 1]);
	line = ft_substr(tmp, 0, i + 1);
	free(tmp);
	tmp = NULL;
	return (line);
}

static char	*ft_newline(int fd, char **buff, char **save)
{
	int		nbytes;
	char	*tmp;

	if (ft_strchr(*save, '\n'))
		return (ft_pull(save));
	nbytes = ft_read(fd, buff, save);
	if ((nbytes == -1 || nbytes == 0) && !**save)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	if (ft_strchr(*save, '\n'))
		return (ft_pull(save));
	if (**save)
	{
		tmp = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (tmp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save[FD_MAX + 1];
	char		*line;
	char		*buff;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	if (!save[fd])
		return (NULL);
	line = ft_newline(fd, &buff, &save[fd]);
	free(buff);
	buff = NULL;
	return (line);
}
