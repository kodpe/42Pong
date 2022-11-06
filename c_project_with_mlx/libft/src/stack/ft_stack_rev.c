/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:09:37 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:19:33 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

void	ft_stack_rev(t_stack *s)
{
	int	index_top;
	int	index_bot;
	int	tmp;

	if (ft_stack_isempty(s))
		return ;
	index_top = s->top;
	index_bot = 0;
	while (index_bot < index_top)
	{
		tmp = s->t[index_top];
		s->t[index_top] = s->t[index_bot];
		s->t[index_bot] = tmp;
		index_top--;
		index_bot++;
	}
}
