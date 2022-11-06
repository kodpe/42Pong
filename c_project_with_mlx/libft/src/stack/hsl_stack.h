/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_stack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:42:38 by zsheep            #+#    #+#             */
/*   Updated: 2022/02/05 07:42:38 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_STACK_H
# define HSL_STACK_H

# include <stdlib.h>
# include "../write/hsl_write.h"
# include "../tab/hsl_tab.h"
# include "../maths/hsl_maths.h"

typedef char	t_bool;

typedef struct s_stack
{
	int	capacity;
	int	top;
	int	*t;
}		t_stack;

/**
 *		ft_stack_add_bottom.c
 */
void	ft_stack_add_bottom(t_stack *s, int x);

/**
 *		ft_stack_del.c
 */
int		ft_stack_del(t_stack *s);

/**
 *		ft_stack_isempty.c
 */
t_bool	ft_stack_isempty(t_stack *s);

/**
 *		ft_stack_isfull.c
 */
t_bool	ft_stack_isfull(t_stack *s);

/**
 *		ft_stack_issort.c
 */
t_bool	ft_stack_ascs(t_stack *s);
t_bool	ft_stack_asc(t_stack *s, int len);
t_bool	ft_stack_des(t_stack *s, int len);
int		ft_stack_ascn(t_stack *s, int n);
int		ft_stack_desn(t_stack *s, int n);

/**
 *		ft_stack_len.c
 */
int		ft_stack_len(t_stack *s);

/**
 *		ft_stack_median.c
 */
int		ft_stack_median(int *median, t_stack *s, int len);

/**
 *		ft_stack_minmax.c
 */
int		ft_stack_min(const t_stack *s, int len);
int		ft_stack_max(const t_stack *s, int len);

/**
 *		ft_stack_new.c
 */
t_stack	*ft_stack_new(int capacity);

/**
 *		ft_stack_peek.c
 */
int		ft_stack_peek(t_stack *s);

/**
 *		ft_stack_pop.c
 */
int		ft_stack_pop(t_stack *s);
int		ft_stack_pop_bottom(t_stack *s);

/**
 *		ft_stack_push.c
 */
void	ft_stack_push(t_stack *s, int x);

/**
 *		ft_stack_rev.c
 */
void	ft_stack_rev(t_stack *s);

/**
 *		ft_stack_show.c
 */
void	ft_stack_show(t_stack *s);

/**
 *		ft_stack_stats.c
 */
void	ft_stack_stats(const t_stack *s, const char *name);

/**
 *		ft_stack_swap_top.c
 */
void	ft_stack_swap_top(t_stack *s);

#endif /* HSL_STACK_H */
