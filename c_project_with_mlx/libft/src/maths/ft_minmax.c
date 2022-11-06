/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:05:55 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/31 09:05:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_maths.h"

/**
 *		a has priority if a == b
 */

long	ft_min(const long a, const long b)
{
	if (a <= b)
		return (a);
	return (b);
}

long	ft_max(const long a, const long b)
{
	if (a >= b)
		return (a);
	return (b);
}
