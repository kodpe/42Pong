/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:56:38 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:17:06 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

t_stack	*ft_stack_new(int capacity)
{
	t_stack	*s;
	int		i;

	if (!capacity)
		return (NULL);
	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->capacity = capacity;
	s->top = -1;
	s->t = (int *)malloc(sizeof(int) * capacity);
	if (!s->t)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (i < capacity)
	{
		s->t[i] = 0;
		i++;
	}
	return (s);
}
