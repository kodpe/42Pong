/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_bottom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:09:00 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:15:41 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

void	ft_stack_add_bottom(t_stack *s, int x)
{
	if (ft_stack_isfull(s))
	{
		ft_printf("\e[0;31mERR ft_stack_add_bottom > isfull\n\e[0m");
		exit(EXIT_FAILURE);
	}
	ft_stack_rev(s);
	s->top++;
	s->t[s->top] = x;
	ft_stack_rev(s);
}
