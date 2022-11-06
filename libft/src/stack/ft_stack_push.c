/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:00:55 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:19:41 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

void	ft_stack_push(t_stack *s, int x)
{
	if (ft_stack_isfull(s))
	{
		ft_printf("\e[0;31mERR ft_stack_push > isfull\n\e[0m");
		exit(EXIT_FAILURE);
	}
	s->top++;
	s->t[s->top] = x;
}
