/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:10:11 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:24:00 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_mem.h"

/**
 * ft_memmove copies n bytes from memory area src to
 * memory area dst. The memory areas may overlap: copying takes
 * place as though the bytes in src are first copied into a
 * temporary array that does not overlap src or dst, and the bytes
 * are then copied from the temporary array to dst.
 */

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (n > 0)
		{
			((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 9 

int	main(void)
{
	void	*src;
	void	*dst;
	size_t	size;
	int	data[SIZE + 1] = {20, 30, 40, 50, 60, 70, 80, 90, 100, 0};

	for (int i = 0; i < SIZE; i++)
		ft_printf("%d ", data[i]);
	puts("");
	src = (void *)data;
	dst = (void *)(data + 1);
	size = SIZE * sizeof(int);
	ft_memmove( dst, src, size);
	//memmove( dst, src, size);
	data[0] = 10;
	for (int i = 0; i < SIZE; i++)
		ft_printf("%d ", data[i]);
	puts("");
	// ok
	char		dest [] = "The cow jumped over the moon";
	const char	sorc []   = "ABCDEFGH"; 
	ft_printf("Avant memmove >> dest = %s, src = %s\n\n" , dest, sorc );
	memmove(dest, sorc, 5);
	ft_printf("Après memmove >> dest = %s, src = %s\n\n" , dest, sorc );
	return (0);
}
*/
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
static int	ft_test(const char *dst, size_t dst_len, const char *src,
	size_t len)
{
	char	*std_dst;
	char	*ft_dst;

	std_dst = (char *)malloc(sizeof(char) * dst_len);
	ft_dst = (char *)malloc(sizeof(char) * dst_len);
	if (!std_dst || !ft_dst)
	{
		ft_printf("Memory allocation error!\n");
		return (1);
	}
	std_dst = (char *)memcpy(std_dst, dst, dst_len);
	ft_dst = (char *)memmove(ft_dst, std_dst, dst_len);
	return (memcmp(memmove(std_dst, src, len),
			ft_memmove(ft_dst, src, len), len));
}

static int	ft_test_overlap(const char *dstsrc, size_t offset, size_t direction,
	size_t len)
{
	char	*std_dstsrc;
	char	*ft_dstsrc;
	int		result;

	std_dstsrc = strdup(dstsrc);
	ft_dstsrc = strdup(dstsrc);
	if (!std_dstsrc || !ft_dstsrc)
	{
		ft_printf("Memory allocation error!\n");
		return (1);
	}
	if (!direction)
	{
		memmove(std_dstsrc, std_dstsrc + offset, len);
		ft_memmove(ft_dstsrc, ft_dstsrc + offset, len);
	}
	else
	{
		memmove(std_dstsrc + offset, std_dstsrc, len);
		ft_memmove(ft_dstsrc + offset, ft_dstsrc, len);
	}
	result = memcmp(std_dstsrc, ft_dstsrc,
			strlen(dstsrc));
	free(std_dstsrc);
	free(ft_dstsrc);
	return (result);
}

int	main(void)
{
	if (ft_test("dst", 12, "src", 6)
		|| ft_test_overlap("dstsrc", 3, 0, 5)
		|| ft_test_overlap("dstsrc", 3, 1, 5))
	{
		ft_printf("KO: ft_memmove\n");
		return (1);
	}
	ft_printf("OK: ft_memmove\n");
}
*/
