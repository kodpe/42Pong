/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:46:17 by sloquet           #+#    #+#             */
/*   Updated: 2022/09/17 02:46:36 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "name.h"

// 0904-0703
int	distance_cart(int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;

	dx = ft_distance_btw_values(x0, x1);
	dy = ft_distance_btw_values(y0, y1);
	return (sqrt(dx * dx + dy * dy));
}
