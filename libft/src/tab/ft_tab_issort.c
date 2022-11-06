/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_issort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:51:18 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/03 06:02:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

/**
 * is sorted biggest to smallest
 */

int	ft_tab_issort_des(const int *tab, const int size)
{
	int	i;

	if (size == 2)
	{
		if (tab[0] > tab[1])
			return (1);
		return (0);
	}
	if (size == 3)
	{
		if (tab[0] > tab[1] && tab[1] > tab[2])
			return (1);
		return (0);
	}
	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/**
 * is sorted smallest to biggest
 */

int	ft_tab_issort_asc(const int *tab, const int size)
{
	int	i;

	if (size == 2)
	{
		if (tab[0] < tab[1])
			return (1);
		return (0);
	}
	if (size == 3)
	{
		if (tab[0] < tab[1] && tab[1] < tab[2])
			return (1);
		return (0);
	}
	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
