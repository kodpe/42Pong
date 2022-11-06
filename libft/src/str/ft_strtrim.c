/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:06:19 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:09:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 * Allocates (with malloc(3)) and returns a copy of
 * ’s1’ with the characters specified in ’set’ removed
 * from the beginning and the end of the string.
 */

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_test(const char *input, const char *reference)
{
	char	*trimmed_str;
	int		result;

	trimmed_str = ft_strtrim(input, "\t\n ");
	if (!trimmed_str)
	{
		ft_printf("Memory allocation error.\n");
		exit(42);
	}
	result = strcmp(reference, trimmed_str);
	free(trimmed_str);
	return (result);
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test(" ", "")
		|| ft_test(" \t\n\t ", "")
		|| ft_test("\tbest\n", "best")
		|| ft_test("O \t\n K", "O \t\n K")
		|| ft_test("continue", "continue")
		|| ft_test("break ;", "break ;")
		|| ft_test(" One Night in Tokyo\t", "One Night in Tokyo"))
	{
		ft_printf("KO: ft_strtrim\n");
		return (1);
	}
	ft_printf("OK: ft_strtrim\n");
	return (0);
}
*/
