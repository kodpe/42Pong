/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:06:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/17 19:25:35 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 * ft_strlcpy copies up to size - 1 characters
 * from the NUL-terminated string src to dst, 
 * null-terminating the result.
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while ((src[i] != '\0') && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

void test(int size)
{
	char	str[] = "The cow jumped over the moon.";
	char	buff[19];
	int		r;
	int		z;

	r = strlcpy(buff, str, size);
	z = ft_strlen(buff);
	ft_printf("cpy %d : '%s' into '%s', length %d %d\n", size, str, buff, r, z);
}

int	main(void)
{
	test(30);
	test(29);
	test(19);
	test(10);
	test(1);
	test(0);
	return (0);
}
*/
