/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:08:36 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:50:27 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_char.h"

/**
 * If c is a lowercase letter, ft_toupper returns its uppercase
 * equivalent, if an uppercase representation exists in the current
 * locale.  Otherwise, it returns c.
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	ft_test(int c)
{
	return (toupper(c) == ft_toupper(c));
}

int	main(void)
{
	int		i;

	i = -1000;
	while (i <= 1000)
	{
		if (!ft_test(i))
		{
			ft_printf("KO: ft_toupper\n");
			return (1);
		}
		i++;
	}
	ft_printf("OK: ft_toupper\n");
}
*/
