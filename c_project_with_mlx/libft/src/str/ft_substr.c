/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:37:27 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/21 17:43:58 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 * Allocates (with malloc(3)) and returns a substring
 * from the string ’s’.
 * The substring begins at index ’start’ and is of
 * maximum size ’len’.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	if (!s)
		write(2, "SEGFAULT ALERT dans GNL_2\n", 26);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
/*
test char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}*/
/*
#include <stdio.h>
#include <string.h>

static int	ft_test(char *string, unsigned int start, size_t length, char *ref)
{
	char	*output;
	int		result;

	output = ft_substr(string, start, length);
	result = strcmp(output, ref);
	free(output);
	return (result);
}

int	main(void)
{
	if (ft_test("", 0, 0, "")
		|| ft_test("ft_substr", 0, 0, "")
		|| ft_test("ft_substr", 0, 1, "f")
		|| ft_test("ft_substr", 1, 0, "")
		|| ft_test("ft_substr", 1, 1, "t")
		|| ft_test("ft_substr", 0, 9, "ft_substr")
		|| ft_test("ft\0strsub", 0, 2, "ft"))
	{
		ft_printf("KO: ft_substr\n");
		return (1);
	}
	ft_printf("OK: ft_substr\n");
	return (0);
}
*/
