/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:09:50 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 13:58:40 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_box.h"

void	ft_box_del(char ***box)
{
	int	z;
	int	y;

	z = 0;
	while (box[z])
	{
		y = 0;
		while (box[z][y])
		{
			free(box[z][y]);
			y++;
		}
		free(box[z]);
		z++;
	}
	free(box);
	box = NULL;
}
