/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:53:42 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:40:52 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_conv.h"

static long	st_abs(long n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int	ft_nbrlen(long nbr, int base)
{
	int	i;

	i = 1;
	if (nbr < 0)
		i++;
	while (st_abs(nbr) >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
