/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_are_distinct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 05:09:14 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 14:31:39 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

/**
 * return 1 si le tableau contient que des valeurs uniques
 */

int	ft_tab_are_distinct(const int *tab, const int size)
{
	int	i;
	int	k;

	i = 0;
	while (i + 1 < size)
	{
		k = i + 1;
		while (k < size)
		{
			if (tab[i] == tab[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
/*
#include <string.h>

int	main(void)
{
	int	tab[10] = {123,122,112,133,423,15,-15,7,8,9};

	ft_printf("are distinct : %d\n", ft_are_distinct(tab, 10));
	return (0);
}
*/

/**
 * return le nombre de valeurs uniques dans un tableau 
 */

int	ft_tab_uniq_count(const int *tab, const int size)
{
	int	count;
	int	i;
	int	k;

	count = 0;
	i = 0;
	while (i + 1 < size)
	{
		k = i + 1;
		while (k < size)
		{
			if (tab[i] == tab[k])
				break ;
			if (k + 1 == size)
				count++;
			k++;
		}
		i++;
	}
	return (count);
}
