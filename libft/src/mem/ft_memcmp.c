/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:54:07 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:23:48 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_mem.h"

/**
 * ft_memcmp compares the first n bytes
 * (each interpreted as unsigned char)
 * of the memory areas s1 and s2.
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	u1;
	unsigned char	u2;

	while (n > 0)
	{
		u1 = *(unsigned char *)s1;
		u2 = *(unsigned char *)s2;
		if (u1 != u2)
			return (u1 - u2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <assert.h>
#include <string.h>

int	main(void)
{
	int array1[] = {54, 85, 20, 63, 21};
	int array2[] = {54, 85, 19, 63, 21};
	size_t	size = sizeof(int) * 5;

	assert(memcmp(array1, array2, size) == ft_memcmp(array1, array2, size));
	assert(memcmp(array1, array1, size) == ft_memcmp(array1, array1, size));
	assert(memcmp(array2, array1, size) == ft_memcmp(array2, array1, size));
	ft_printf("Test is ok\n");
	return (0);
}
*/
