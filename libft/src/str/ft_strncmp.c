/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:20:13 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:09:16 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 * ft_strncmp compare not more than n bytes
 * (bytes that follow a NUL character are not compared)
 * from the array pointed to by s1 to the array pointed to by s2.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && (n > 0))
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_test(const char *s1, const char *s2, size_t len)
{
	char	*string1;
	char	*string2;
	int		std_result;
	int		ft_result;

	string1 = strdup(s1);
	string2 = strdup(s2);
	std_result = strncmp(string1, string2, len);
	ft_result = ft_strncmp(string1, string2, len);
	free(string1);
	free(string2);
	return (std_result == ft_result);
}

int	main(void)
{
	if (!ft_test("", "", 0)
		|| !ft_test("", "", 1)
		|| !ft_test("test", "test", 0)
		|| !ft_test("test", "test", (size_t)(-23))
		|| !ft_test("aest", "fest", 0)
		|| !ft_test("best", "zest", 10)
		|| !ft_test("ok", "oko", 2)
		|| !ft_test("abc", "abe", 5)
		|| !ft_test("ab\0de", "ab\0cde", 5)
		|| !ft_test("a\0bde", "ab\0cde", 5)
		|| !ft_test("a\0bde", "zy\0xwv", 5))
	{
		ft_printf("KO: ft_strncmp\n");
		return (1);
	}
	ft_printf("OK: ft_strncmp\n");
}
*/
