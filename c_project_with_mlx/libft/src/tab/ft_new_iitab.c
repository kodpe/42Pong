/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_iitab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:49:46 by sloquet           #+#    #+#             */
/*   Updated: 2022/03/18 22:21:31 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

int	**ft_new_iitab(const int xlen, const int ylen, const int val)
{
	int	**tab;
	int	i;

	tab = (int **)malloc(sizeof(int *) * ylen);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ylen)
	{
		tab[i] = (int *)malloc(sizeof(int) * xlen);
		if (!tab[i])
		{
			while (i--)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
		i++;
	}
	ft_set_iitab(tab, xlen, ylen, val);
	return (tab);
}
