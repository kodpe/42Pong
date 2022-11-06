/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:41:21 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:08:51 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 * Applies the function f to each character of the
 * string passed as argument, and passing its index
 * as first argument. Each character is passed by
 * address to f to be modified if necessary
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static void	ft_alternate_case(unsigned int i, char *c)
{
	if (!(i % 2))
		*c = (char)toupper(*c);
	else
		*c = (char)tolower(*c);
}

static int	ft_test(const char *s, const char *reference)
{
	char	*str;
	int		result;

	str = strdup(s);
	if (!str)
	{
		ft_printf("Memory allocation error.\n");
		exit(42);
	}
	ft_striteri(str, &ft_alternate_case);
	result = strcmp(str, reference);
	free(str);
	return (result);
}

int	main(void)
{
	if (ft_test("", "")
		|| ft_test("alternate_case", "AlTeRnAtE_CaSe")
		|| ft_test("OK: ft_striteri", "Ok: Ft_sTrItErI")
		|| ft_test("qwertyuiopasdfghjklzxcvbnm", "QwErTyUiOpAsDfGhJkLzXcVbNm")
		|| ft_test("QWERTYUIOPASDFGHJKLZXCVBNM", "QwErTyUiOpAsDfGhJkLzXcVbNm"))
	{
		ft_printf("KO: ft_striteri\n");
		return (1);
	}
	ft_printf("OK: ft_striteri\n");
	return (0);
}
*/
