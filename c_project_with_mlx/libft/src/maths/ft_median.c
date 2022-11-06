/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 07:29:56 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 09:56:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_maths.h"

/*
static int	part(int *array, int len)
{
	int		iinf;
	int		isup;
	int		tmp[len];
	int		i;

	iinf = 0;
	isup = len - 1;
	i = -1;
	while (++i < len - 1)
	{
		if (array[i] > array[len - 1])
			tmp[isup--] = array[i];
		else
			tmp[iinf++] = array[i];
	}
	tmp[iinf] = array[len - 1];
	i = -1;
	while (++i < len)
		array[i] = tmp[i];
	return (iinf);
}

static void	simple_qsort(int *array, int len)
{
	int		i;

	if (len < 2)
		return ;
	i = part(array, len);
	if (i)
		simple_qsort(array, i);
	if (i != len - 1)
		simple_qsort(array + i + 1, len - i - 1);
}*/

int	ft_median(int *median, const int *tab, int size)
{
	int		*tmp;

	tmp = ft_tabdup(tab, size);
	if (!tmp)
		return (0);
	ft_sort_int_tab(tmp, size);
	*median = tmp[size / 2];
	free(tmp);
	return (1);
}
