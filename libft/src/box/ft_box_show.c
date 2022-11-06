/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 06:08:47 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 13:58:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_box.h"

void	ft_box_show(char ***box)
{
	int	h;
	int	z;
	int	y;
	int	x;

	h = (int)ft_box_ylen(box) - 1;
	z = 0;
	while (box[z])
	{
		y = 0;
		while (box[z][y])
		{
			x = 0;
			while (x < h - y)
			{
				ft_printf(" ");
				x++;
			}
			ft_printf("%s", box[z][y]);
			ft_printf("\n");
			y++;
		}
		ft_printf("\n");
		z++;
	}
}
