/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 05:17:39 by sloquet           #+#    #+#             */
/*   Updated: 2022/06/23 12:21:48 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_write.h"

static size_t	st_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putx_fd(int fd, int n, char *s)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(fd, s, st_strlen(s));
		i++;
	}
}

void	ft_putxnl_fd(int fd, int n, char *s)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(fd, s, st_strlen(s));
		i++;
	}
	ft_putnl_fd(fd);
}
