/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_crc32.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:12:05 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:31:33 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_hash.h"

/**
 * brief 32-bit CRC algorithm implementation
 *
 * param s NULL terminated ASCII string to hash
 * return 32-bit hash result
 */
uint32_t	ft_hash_crc32(const char *s)
{
	uint32_t	crc;
	size_t		i;
	uint8_t		byte;
	uint8_t		j;

	crc = 0xffffffff;
	i = 0;
	while (s[i] != '\0')
	{
		byte = s[i];
		crc = crc ^ byte;
		j = 8;
		while (j > 0)
		{
			crc = (crc >> 1) ^ (0xEDB88320 & (-(crc & 1)));
			--j;
		}
		i++;
	}
	return (crc ^ 0xffffffff);
}
/*
#include <assert.h>
#include <stdio.h>

void	test_crc32(void)
{
	assert(ft_hash_crc32("Hello World") == 1243066710);
	assert(ft_hash_crc32("Hello World!") == 472456355);
	assert(ft_hash_crc32("Hello world") == 2346098258);
	assert(ft_hash_crc32("Hello world!") == 461707669);
	ft_printf("%d\n", ft_hash_crc32("Hello world!"));
	ft_printf("Tests passed\n");
}

int	main(void)
{
	test_crc32();
	return (0);
}
*/
