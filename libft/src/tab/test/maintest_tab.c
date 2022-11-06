/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:05:43 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:04:48 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hsl_tab.h"

int	main(int ac, char **av)
{
	int	res;
	int	*dup;
	int	tab[4];

	(void)ac;
	(void)av;
	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	tab[3] = 3;
	res = ft_tab_are_distinct(tab, 4);
	res = ft_tab_uniq_count(tab, 4);
	dup = ft_tabdup(tab, 4);
	ft_tabshow(dup, 4, "dup");
	free(dup);
	res = ft_tab_issort_des(tab, 4);
	res = ft_tab_issort_asc(tab, 4);
	res = ft_tab_median(tab, 4);
	res = ft_tab_first_quar(tab, 4);
	res = ft_tab_third_quar(tab, 4);
	res = ft_tab_min(tab, 4);
	res = ft_tab_max(tab, 4);
	ft_tabshow(tab, 4, "tab");
	(void)res;
	return (0);
}
