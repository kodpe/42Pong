/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:08:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:18:15 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

void	ft_stack_swap_top(t_stack *s)
{
	int	tmp;

	if (ft_stack_len(s) < 2)
		return ;
	tmp = s->t[s->top];
	s->t[s->top] = s->t[s->top - 1];
	s->t[s->top - 1] = tmp;
}
