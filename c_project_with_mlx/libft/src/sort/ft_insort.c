/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:44:54 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 09:09:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_sort.h"

void	ft_insort_asc(int *tab, int size)
{
	int	i;
	int	k;
	int	val;

	ft_printf("ft_insort.c:ft_insort_asc:21 DEPRECATED FUNCTION\n");
	i = 1;
	while (i < size)
	{
		val = tab[i];
		k = i - 1;
		i++;
		while (val < tab[k] && k >= 0)
		{
			tab[k + 1] = tab[k];
			k--;
		}
		tab[k + 1] = val;
	}
}

void	ft_insort_des(int *tab, int size)
{
	int	i;
	int	k;
	int	val;

	ft_printf("ft_insort.c:ft_insort_des:43 DEPRECATED FUNCTION\n");
	i = 1;
	while (i < size)
	{
		val = tab[i];
		k = i - 1;
		i++;
		while (val > tab[k] && k >= 0)
		{
			tab[k + 1] = tab[k];
			k--;
		}
		tab[k + 1] = val;
	}
}
