/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:39:40 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:38:49 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_conv.h"

static int	ft_len_base(char *base)
{
	int	i;
	int	r;

	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] == 32) || (base[i] >= 9 && base[i] <= 13))
			return (1);
		if ((base[i] == 43) || (base[i] == 45))
			return (1);
		r = i;
		while (base[r] != '\0')
		{
			if ((base[i] == base[r]) && (i != r))
				return (1);
			r++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (i);
}

static int	ft_char_index_base(unsigned char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nb;
	int	i;

	if (ft_len_base(base) == 1)
		return (0);
	sign = 1;
	nb = 0;
	i = 0;
	while ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_char_index_base(str[i], base) >= 0)
	{
		nb = (nb * ft_len_base(base) + ft_char_index_base(str[i], base));
		i++;
	}
	return (nb * sign);
}
