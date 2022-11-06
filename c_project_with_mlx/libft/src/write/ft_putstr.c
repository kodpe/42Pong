/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:12:42 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/01 06:46:00 by sloquet          ###   ########.fr       */
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

void	ft_putstr(const char *s)
{
	if (!s)
		return ;
	write(1, s, st_strlen(s));
}

void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, st_strlen(s));
}

/**
 * Outputs the string ’s’ to the given file descriptor, followed by a newline.
 */

void	ft_putsnl(const char *s)
{
	if (!s)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}

void	ft_putsnl_fd(const char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
