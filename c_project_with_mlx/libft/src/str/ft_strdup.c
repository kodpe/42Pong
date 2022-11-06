/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:04:09 by sloquet           #+#    #+#             */
/*   Updated: 2022/06/15 21:19:28 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 * The strdup() function returns a pointer to a new string which is
 * a duplicate of the string s.  Memory for the new string is
 * obtained with malloc(3), and can be freed with free(3).
 */
char	*ft_strdup(const char *src)
{
	char	*new;

	if (!src)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	ft_strcpy(new, src);
	return (new);
}

char	*ft_strldup(const char *src, size_t size)
{
	char	*new;

	if (!src)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, src, size);
	return (new);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	ft_test(const char *string)
{
	char	*std_str;
	char	*ft_str;
	int		result;

	std_str = strdup(string);
	ft_str = ft_strdup(string);
	result = strcmp(std_str, ft_str);
	ft_printf("in :%s\n", string);
	ft_printf("std_str :%s\n", std_str);
	ft_printf("ft_str :%s\n", ft_str);
	free(std_str);
	free(ft_str);
	return (result);
}

int	main(void)
{
	if (ft_test("Unbreakable")
		|| ft_test("") || ft_test("a"))
	{
		ft_printf("KO: ft_strdup");
		return (1);
	}
	ft_printf("OK: ft_strdup");
	// char *test= "0wf9rer908098";
	char *test = NULL; // ! standard strdup() segfault on NULL
	ft_test(test);
	// free(test);
}
*/
