/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_debug_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:06:35 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 21:13:24 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_debug.h"

char	*dbg_display_file_range(char *filepath, int line, int range)
{
	char	*cmd;
	char	*head;
	char	*tail;

	if (!filepath)
		return (NULL);
	head = ft_itoabtw("head -n ", line + range, " ");
	if (!head)
		return (NULL);
	tail = ft_itoabtw(" | tail -n ", range * 2 + 1, "");
	if (!tail)
	{
		free(head);
		return (NULL);
	}
	cmd = ft_strjointri(head, filepath, tail);
	free(head);
	free(tail);
	return (cmd);
}

void	dbg_cmd(char *_FI, int _LN, int mark)
{
	char	*cmd;

	if (mark)
	{
		ft_putstr_fd("\e[0;33m> \e[0m", 2);
		ft_putx_fd(2, 4 - ft_nbrlen(_LN, 10), " ");
	}
	else
		ft_putx_fd(2, 6 - ft_nbrlen(_LN, 10), " ");
	ft_dprintf(2, "\e[0;32m%d\e[0;36m:\e[2;36m", _LN);
	cmd = dbg_display_file_range(_FI, _LN, 0);
	if (system(cmd))
		ft_dprintf(2, "ERROR dbg5 > cmd %s\n", cmd);
	free(cmd);
}

void	dbg_assert(int value, int correct_value)
{
	ft_putx_fd(2, 7, " ");
	ft_putstr_fd("\e[0m", 2);
	if (value == correct_value)
		ft_dprintf(2, "\e[0;32mOK %d == %d\n\e[0m", value, correct_value);
	else
		ft_dprintf(2, "\e[0;31mKO %d != %d\n\e[0m", value, correct_value);
}
