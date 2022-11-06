/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:09:40 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 14:35:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_sort.h"

static int	ft_index_upper_tab(int *tab, int siz)
{
	int	upper;

	upper = 0;
	while (siz > 0)
	{
		siz--;
		if (tab[siz] > tab[upper])
			upper = siz;
	}
	return (upper);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	index_upper;

	while (size > 0)
	{
		size--;
		index_upper = ft_index_upper_tab(tab, (size + 1));
		ft_intswap(&tab[size], &tab[index_upper]);
	}
}
