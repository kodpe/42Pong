/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:38:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/27 15:29:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_io.h"

int	sc_dup(int old_fd)
{
	int	new_fd;

	if (old_fd == -1)
	{
		if (SHOW_IO)
			return (sc_write(2, "sc_dup() -1\n", WRITE_ERROR), -1);
		else
			return (-1);
	}
	new_fd = dup(old_fd);
	if (new_fd == -1)
		perror("sc_dup");
	return (new_fd);
}
