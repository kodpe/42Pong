/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_peek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:01:28 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:17:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

int	ft_stack_peek(t_stack *s)
{
	if (ft_stack_isempty(s))
	{
		ft_printf("\e[0;31mERR ft_stack_peek > isempty\n\e[0m");
		exit(EXIT_FAILURE);
	}
	return (s->t[s->top]);
}
