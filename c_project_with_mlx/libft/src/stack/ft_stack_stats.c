/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_stats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 08:50:11 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/05 07:41:59 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_stack.h"

static void	ft_summary(const t_stack *s, const char *name)
{
	ft_printf("\n%s.top  : %d/%d", name, s->top, s->capacity);
	ft_printf(" min.i %d", ft_stack_min(s, s->top + 1));
	ft_printf(" max.i %d\n", ft_stack_max(s, s->top + 1));
}

void	ft_stack_stats(const t_stack *s, const char *name)
{
	int	i;
	int	p;

	if (!s)
		return ;
	ft_summary(s, name);
	i = s->top;
	while (i >= 0)
	{
		if (i > 0)
			if (s->t[i] < s->t[i - 1])
				ft_printf("\e[34m");
		ft_printf("%s.t[%d] = %d", name, i, s->t[i]);
		ft_printf("\e[0m");
		p = s->t[i] / 2;
		if (p < 80)
		{
			while (p-- > 0)
				ft_printf("\e[1;32m_\e[0m");
		}
		ft_printf("\n");
		i--;
	}
}
