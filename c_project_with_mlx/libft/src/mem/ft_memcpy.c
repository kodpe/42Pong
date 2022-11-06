/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:00:00 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:23:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_mem.h"

/**
 * ft_memcpy copies n bytes from memory area src to
 * memory area dst. The memory areas must not overlap.
 */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	tmp = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*tmp++ = *s++;
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
char src[] = "The cow jumped over the moon.";
char dest[100];
ft_memcpy(dest, src, strlen(src) + 1);
ft_printf("cpy str is %s\n", dest);

int tab[] = {10, 20, 30, 40, 50};
int n = sizeof(tab) / sizeof(tab[0]);
int idest[n];
ft_memcpy(idest, tab, sizeof(tab));
ft_printf("cpy array is ");
for (int i = 0; i < n; i++)
        ft_printf("%d ", idest[i]);
    ft_printf("\n");
    return (0);
}
*/
