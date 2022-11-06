/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_median.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 06:44:47 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 09:13:05 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

int	ft_stack_median(int *median, t_stack *s, int len)
{
	int		*tmp;

	tmp = ft_tabdup_range(s->t, s->top - (len - 1), s->top);
	if (!tmp)
		return (0);
	ft_sort_int_tab(tmp, len);
	*median = tmp[len / 2];
	free(tmp);
	return (1);
}
