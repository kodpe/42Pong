/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_sort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:18:28 by zsheep            #+#    #+#             */
/*   Updated: 2022/02/05 09:07:57 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_SORT_H
# define HSL_SORT_H

# include "../write/hsl_write.h"

/**
 *		ft_insort.c
 */
void	ft_insort_asc(int *tab, int size);
void	ft_insort_des(int *tab, int size);

/**
 *		ft_intswap.c
 */
void	ft_intswap(int *a, int *b);

/**
 *		ft_qsort.c
 */
void	ft_qsort_asc(int *tab, int low, int high);
void	ft_qsort_des(int *tab, int low, int high);

/**
 *		ft_rev_int_tab.c
 */
void	ft_rev_int_tab(int *tab, int size);

/**
 *		ft_sort_int_tab.c
 */
void	ft_sort_int_tab(int *tab, int size);

#endif /* HSL_SORT_H */
