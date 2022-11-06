/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_maths.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:18:38 by zsheep            #+#    #+#             */
/*   Updated: 2022/03/18 22:35:10 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_MATHS_H
# define HSL_MATHS_H

# include "../sort/hsl_sort.h"
# include "../tab/hsl_tab.h"

/**
 *		ft_abs.c
 */
long	ft_abs(long n);

/**
 * 		ft_distance_btw_values.c
 */
int		ft_distance_btw_values(const int a, const int b);
/**
 *		ft_factorial.c
 */
int		ft_factorial(int nb);

/**
 *		ft_fibonacci.c
 */
int		ft_fibonacci(int index);

/**
 *		ft_isprime.c
 */
int		ft_isprime(int nb);

/**
 *		ft_median.c
 */
int		ft_median(int *median, const int *tab, int size);

/**
 *		ft_minmax.c
 */
long	ft_min(const long a, const long b);
long	ft_max(const long a, const long b);

/**
 *		ft_nextprime.c
 */
int		ft_nextprime(int nb);

/**
 *		ft_power.c
 */
int		ft_power(int nb, int power);

/**
 *		ft_sqrt.c
 */
int		ft_sqrt(int nb);

#endif /* HSL_MATHS_H */
