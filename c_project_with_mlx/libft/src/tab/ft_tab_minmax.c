/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_minmax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:30:38 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 14:33:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

int	ft_tab_min(const int *tab, const int size)
{
	int	i;
	int	min;
	int	index_min;

	if (size <= 0)
		return (-1);
	min = tab[0];
	index_min = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			index_min = i;
		}
		i++;
	}
	return (index_min);
}

int	ft_tab_max(const int *tab, const int size)
{
	int	i;
	int	max;
	int	index_max;

	if (size <= 0)
		return (-1);
	max = tab[0];
	index_max = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			index_max = i;
		}
		i++;
	}
	return (index_max);
}
