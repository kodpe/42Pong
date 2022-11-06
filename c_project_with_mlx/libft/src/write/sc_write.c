/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:46:23 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/25 12:25:04 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"

int	sc_write(const int fd, const char *str, const char *error_msg)
{
	size_t	n;

	if (!str)
		return (1);
	n = 0;
	while (str[n])
		n++;
	if (0 > write(fd, str, n))
	{
		perror(error_msg);
		return (1);
	}
	return (0);
}
