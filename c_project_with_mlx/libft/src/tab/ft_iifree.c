/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iifree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:55:04 by sloquet           #+#    #+#             */
/*   Updated: 2022/03/17 16:56:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

void	ft_iifree(int **tab, const int ylen)
{
	int	y;

	if (!tab)
		return ;
	y = 0;
	while (y < ylen)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
	tab = NULL;
}
