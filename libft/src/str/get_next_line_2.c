/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:10:49 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 11:20:52 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

#define BUFFER_SIZE 1

#define FD_MAX 1024
#define SUCCESS 0
#define ERR_MALLOC 1
#define ERR_INIT 2

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

static int	ft_read(int fd, char **buff, char **save, int *ret)
{
	int		nbytes;
	char	*tmp;

	nbytes = 1;
	while (nbytes && !ft_strchr(*save, '\n'))
	{
		nbytes = read(fd, *buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			perror("get_next_line");
			return (-1);
		}
		(*buff)[nbytes] = 0;
		tmp = *save;
		*save = ft_strjoin(tmp, *buff);
		if (!*save)
			*ret = ERR_MALLOC;
		free(tmp);
		tmp = NULL;
	}
	return (nbytes);
}

static char	*ft_pull(char **save, int *ret)
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
	if (!*save || !line)
		*ret = ERR_MALLOC;
	free(tmp);
	tmp = NULL;
	return (line);
}

static char	*ft_newline(int fd, char **buff, char **save, int *ret)
{
	int		nbytes;
	char	*tmp;

	if (ft_strchr(*save, '\n'))
		return (ft_pull(save, ret));
	nbytes = ft_read(fd, buff, save, ret);
	if ((nbytes == -1 || nbytes == 0) && !**save)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}
	if (ft_strchr(*save, '\n'))
		return (ft_pull(save, ret));
	if (**save)
	{
		tmp = ft_strdup(*save);
		free(*save);
		*save = NULL;
		if (!tmp)
			*ret = ERR_MALLOC;
		return (tmp);
	}
	return (NULL);
}

int	gnl_nagic(int fd, char **save)
{
	int	i;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
	{
		i = 0;
		while (i <= 1024)
		{
			if (save[i])
			{
				free(save[i]);
				save[i] = NULL;
			}
			i++;
		}
		return (0);
	}
	return (1);
}

char	*get_next_line_2(int fd, int *ret)
{
	static char	*save[FD_MAX + 1];
	char		*buff;
	char		*line;

	if (!gnl_nagic(fd, save))
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	if (!save[fd])
		return (NULL);
	line = ft_newline(fd, &buff, &save[fd], ret);
	free(buff);
	if (*ret == 1)
		return (NULL);
	return (line);
}
