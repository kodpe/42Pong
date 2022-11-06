/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iishow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:58:38 by sloquet           #+#    #+#             */
/*   Updated: 2022/03/17 16:59:43 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tab.h"

void	ft_iishow(int **tab, const int xlen, const int ylen)
{
	int	x;
	int	y;

	if (!tab)
		return ;
	y = 0;
	while (y < ylen)
	{
		x = 0;
		while (x < xlen)
		{
			ft_printf("%d ", tab[y][x]);
			x++;
		}
		ft_putnl();
		y++;
	}
}
