/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:02:03 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:17:36 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

int	ft_stack_pop(t_stack *s)
{
	int	x;

	x = ft_stack_peek(s);
	s->t[s->top] = 0;
	s->top--;
	return (x);
}

int	ft_stack_pop_bottom(t_stack *s)
{
	int	x;

	if (ft_stack_isempty(s))
	{
		ft_printf("\e[0;31mERR ft_stack_pop_bottom > isempty\n\e[0m");
		exit(EXIT_FAILURE);
	}
	ft_stack_rev(s);
	x = s->t[s->top];
	s->t[s->top] = 0;
	s->top--;
	ft_stack_rev(s);
	return (x);
}
