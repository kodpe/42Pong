/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:15:31 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/31 06:44:44 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_debug.h"

void	dbv(char *_FI, int _LN, char *debug_msg, int variable)
{
	int	i;

	ft_dprintf(2, "\n\e[0;35m%s\e[0;36m:\e[0;32m%d\e[0;36m:", _FI, _LN);
	ft_dprintf(2, "\e[0;33m %s\e[2;36m\n", debug_msg);
	ft_putxnl_fd(2, 42, "-");
	i = 3;
	while (i > 0)
	{
		dbg_cmd(_FI, _LN - i, 0);
		i--;
	}
	dbg_cmd(_FI, _LN, 1);
	ft_dprintf(2, "\e[0;33m       %s = %d\n\e[2;36m", debug_msg, variable);
	i++;
	while (i < 5)
	{
		dbg_cmd(_FI, _LN + i, 0);
		i++;
	}
	ft_putxnl_fd(2, 42, "-");
	ft_dprintf(2, "\e[0;33mPaused...\e[0m");
	getchar();
}

void	dba(char *_FI, int _LN, int variable, int correct_value)
{
	int	i;

	ft_dprintf(2, "\n\e[0;35m%s\e[0;36m:\e[0;32m%d\e[0;36m:", _FI, _LN);
	ft_dprintf(2, "\e[0;33m assert\e[2;36m\n");
	ft_putxnl_fd(2, 42, "-");
	i = 3;
	while (i > 0)
	{
		dbg_cmd(_FI, _LN - i, 0);
		i--;
	}
	dbg_cmd(_FI, _LN, 1);
	dbg_assert(variable, correct_value);
	while (i < 3)
	{
		dbg_cmd(_FI, _LN + i, 0);
		i++;
	}
	ft_putxnl_fd(2, 42, "-");
	ft_dprintf(2, "\e[0;33mPaused...\e[0m");
	getchar();
}
