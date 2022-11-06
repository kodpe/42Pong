/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_firstquart.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:29:30 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 11:29:38 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

int	ft_tab_firstquart(const int *tab, const int size)
{
	int	*tmp;
	int	q;

	tmp = ft_tabdup(tab, size);
	if (!tmp)
		return (-1);
	ft_sort_int_tab(tmp, size);
	q = tmp[size / 4];
	free(tmp);
	return (q);
}
