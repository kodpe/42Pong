/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_issort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:10:51 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/03 08:04:33 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

t_bool	ft_stack_ascs(t_stack *s)
{
	int	i;

	i = 0;
	while (i + 1 < s->top + 1)
	{
		if (s->t[i] < s->t[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_bool	ft_stack_asc(t_stack *s, int len)
{
	int	i;

	i = s->top;
	while (i > s->top - (len - 1))
	{
		if (s->t[i] > s->t[i - 1])
			return (0);
		i--;
	}
	return (1);
}

t_bool	ft_stack_des(t_stack *s, int len)
{
	int	i;

	i = s->top;
	while (i > s->top - (len - 1))
	{
		if (s->t[i] < s->t[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	ft_stack_ascn(t_stack *s, int n)
{
	if (n > s->top)
		return (-1);
	while (n > 0)
	{
		if (s->t[n] > s->t[n - 1])
			return (n);
		n--;
	}
	return (n);
}

int	ft_stack_desn(t_stack *s, int n)
{
	if (n > s->top)
		return (-1);
	while (n > 0)
	{
		if (s->t[n] < s->t[n - 1])
			return (n);
		n--;
	}
	return (n);
}
