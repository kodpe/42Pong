/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:51:48 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 15:28:57 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_io.h"

int	sc_close_std(int fd)
{
	close(fd);
	return (0);
}

int	sc_close(int *fd)
{
	if (*fd == -1)
	{
		if (SHOW_IO)
			return (sc_write(2, "sc_close() -1\n", WRITE_ERROR), -1);
		else
			return (-1);
	}
	if (close(*fd) == -1)
		return (perror("sc_close"), -1);
	return (*fd = -1, 0);
}

void	sc_2close(int *fd1, int *fd2)
{
	sc_close(fd1);
	sc_close(fd2);
}

void	sc_3close(int *fd1, int *fd2, int *fd3)
{
	sc_close(fd1);
	sc_close(fd2);
	sc_close(fd3);
}
