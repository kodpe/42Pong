/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_btw_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:23:51 by sloquet           #+#    #+#             */
/*   Updated: 2022/03/18 22:36:12 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_maths.h"

int	ft_distance_btw_values(const int a, const int b)
{
	int	min;
	int	max;

	if (a == b)
		return (0);
	if (a < b)
	{
		min = a;
		max = b;
	}
	if (a > b)
	{
		max = a;
		min = b;
	}
	if (min >= 0)
		return (max - min);
	if (max < 0)
		return (ft_abs(min - max));
	return (ft_abs(min) + max);
}
