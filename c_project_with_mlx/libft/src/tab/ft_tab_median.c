/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 07:12:27 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/04 14:18:20 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

int	ft_tab_median(const int *tab, const int size)
{
	int	*tmp;
	int	median;

	ft_printf("ft_tab_median.c:ft_tab_median:20 DEPRECATED FUNCTION\n");
	median = 0;
	tmp = ft_tabdup(tab, size);
	if (!tmp)
		return (-1);
	ft_qsort_asc(tmp, 0, size - 1);
	if (size % 2 == 1)
		median = tmp[size / 2];
	if (size % 2 == 0)
		median = (tmp[size / 2 - 1] + tmp[size / 2]) / 2;
	free(tmp);
	return (median);
}

int	ft_tab_first_quar(const int *tab, const int size)
{
	int	*tmp;
	int	first_quar;

	ft_printf("ft_tab_median.c:ft_tab_first_quar:39 DEPRECATED FUNCTION\n");
	first_quar = 0;
	tmp = ft_tabdup(tab, size);
	if (!tmp)
		return (-1);
	ft_qsort_asc(tmp, 0, size - 1);
	if (size % 2 == 1)
		first_quar = tmp[size / 4];
	if (size % 2 == 0)
		first_quar = tmp[(size / 4) - 1];
	free(tmp);
	return (first_quar);
}

int	ft_tab_third_quar(const int *tab, const int size)
{
	int	*tmp;
	int	third_quar;

	ft_printf("ft_tab_median.c:ft_tab_third_quar:58 DEPRECATED FUNCTION\n");
	tmp = ft_tabdup(tab, size);
	if (!tmp)
		return (-1);
	ft_qsort_asc(tmp, 0, size - 1);
	if (size % 2 == 1)
		third_quar = tmp[size - (size / 4) - 1];
	if (size % 2 == 0)
		third_quar = tmp[size - (size / 4)];
	free(tmp);
	return (third_quar);
}

/**
	ft_tabshow(tmp, size, "tab");
	ft_tabshow(tmp, size, "tmp");
	**/

/**
 * To do - Median-of-medians Algorithm
 */
