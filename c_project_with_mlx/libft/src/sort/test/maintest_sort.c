/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:05:43 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 14:53:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hsl_sort.h"

int	main(int ac, char **av)
{
	int	tab[4];

	(void)ac;
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;
	ft_insort_des(tab, 4);
	ft_insort_asc(tab, 4);
	ft_intswap(&tab[0], &tab[1]);
	ft_qsort_asc(tab, 0, 1);
	ft_qsort_des(tab, 0, 3);
	ft_rev_int_tab(tab, 4);
	ft_sort_int_tab(tab, 4);
	return (0);
}
/*
	gcc *.c ../../tab/*.c ../../sort/*.c ../../write/*.c

	#include "../../tab/hsl_tab.h"

	ft_tabshow(tab, 4, "init");
	ft_insort_des(tab, 4);
	ft_tabshow(tab, 4, "insort_des");
	ft_insort_asc(tab, 4);
	ft_tabshow(tab, 4, "insort_asc");
	ft_intswap(&tab[0], &tab[1]);
	ft_tabshow(tab, 4, "swap 0 - 1");
	ft_qsort_asc(tab, 0, 1);
	ft_tabshow(tab, 4, "qsort_asc");
	ft_qsort_des(tab, 0, 3);
	ft_tabshow(tab, 4, "qsort_des");
	ft_rev_int_tab(tab, 4);
	ft_tabshow(tab, 4, "rev_int_tab");
	ft_sort_int_tab(tab, 4);
	ft_tabshow(tab, 4, "sort_int_tab");
*/
