/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:12:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:09:12 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 * Applies the function ’f’ to each character of
 * the string ’s’ , and passing its index as first
 * argument to create a new string (with malloc(3))
 * resulting from successive applications of ’f’.
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	new = ft_strdup(s);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static char	ft_alternate_case(unsigned int i, char c)
{
	if (!(i % 2))
		return ((char)toupper(c));
	else
		return ((char)tolower(c));
}

static int	ft_test(const char *s, const char *reference)
{
	char	*str;
	int		result;

	str = ft_strmapi(s, &ft_alternate_case);
	if (!str)
	{
		ft_printf("Memory allocation error.\n");
		exit(42);
	}
	result = strcmp(str, reference);
	free(str);
	return (result);
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test("ft_alternate_case", "Ft_aLtErNaTe_cAsE")
		|| ft_test("OK: ft_strmapi", "Ok: Ft_sTrMaPi")
		|| ft_test("qwertyuiopasdfghjklzxcvbnm", "QwErTyUiOpAsDfGhJkLzXcVbNm")
		|| ft_test("QWERTYUIOPASDFGHJKLZXCVBNM", "QwErTyUiOpAsDfGhJkLzXcVbNm"))
	{
		ft_printf("KO: ft_strmapi\n");
		return (1);
	}
	ft_printf("OK: ft_strmapi\n");
	return (0);
}
*/
