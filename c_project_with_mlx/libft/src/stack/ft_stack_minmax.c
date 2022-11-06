/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_minmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:41:42 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 07:42:30 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

int	ft_stack_min(const t_stack *s, int len)
{
	int	i;
	int	min;
	int	index_min;

	if (len <= 0)
		return (-1);
	i = s->top;
	index_min = i;
	min = s->t[i];
	while (len)
	{
		if (s->t[i] < min)
		{
			min = s->t[i];
			index_min = i;
		}
		len--;
		i--;
	}
	return (index_min);
}

int	ft_stack_max(const t_stack *s, int len)
{
	int	i;
	int	max;
	int	index_max;

	if (len <= 0)
		return (-1);
	i = s->top;
	index_max = i;
	max = s->t[i];
	while (len)
	{
		if (s->t[i] > max)
		{
			max = s->t[i];
			index_max = i;
		}
		len--;
		i--;
	}
	return (index_max);
}
