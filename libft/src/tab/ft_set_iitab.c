/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_iitab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:52:18 by sloquet           #+#    #+#             */
/*   Updated: 2022/03/17 16:53:57 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

void	ft_set_iitab(int **tab, const int xlen, const int ylen, const int val)
{
	int	x;
	int	y;

	y = 0;
	while (y < ylen)
	{
		x = 0;
		while (x < xlen)
		{
			tab[y][x] = val;
			x++;
		}
		y++;
	}
}
