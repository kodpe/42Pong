/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 07:25:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/03 07:15:39 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

int	*ft_tabdup(const int *tab, const int size)
{
	int	*dup;
	int	i;

	if (size <= 0)
		return (NULL);
	dup = (int *)malloc(sizeof(int) * size);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = tab[i];
		i++;
	}
	return (dup);
}

int	*ft_tabdup_range(const int *tab, const int start, const int end)
{
	int	*dup;
	int	i;
	int	size;

	if (start < 0 || start > end)
		return (NULL);
	size = (end - start) + 1;
	dup = (int *)malloc(sizeof(int) * size);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = tab[start + i];
		i++;
	}
	return (dup);
}

/*
int	main(void)
{
	int	*tab;

	tab = (int *)malloc(sizeof(int) * 5);
	tab[0] = 10;
	tab[1] = 11;
	tab[2] = 22;
	tab[3] = 33;
	tab[4] = 44;
	for (int i = 0; i < 5; i++)
		ft_printf("tab[%d]= %d\n", i, tab[i]);
	int	*dup;
	dup = ft_tabdup_range(tab, 2, 4);
	if (!dup)
		return (0);
	ft_printf("\n");
	ft_printf("dup[0]= %d\n", dup[0]);
	ft_printf("dup[1]= %d\n", dup[1]);
	ft_printf("dup[2]= %d\n", dup[2]);
	// ft_printf("dup[3]= %d\n", dup[3]);
	// ft_printf("dup[4]= %d\n", dup[4]);
	free(dup);
	free(tab);
	return (0);
}
*/
