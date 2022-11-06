/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:41:05 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/28 15:28:41 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_io.h"

int	sc_dup2(int old_fd, int new_fd)
{
	int	ret_fd;

	if (SHOW_IO)
	{
		if (new_fd == STDIN_FILENO)
			sc_write(2, "sc_dup2 STDIN close 0\n", WRITE_ERROR);
		if (new_fd == STDOUT_FILENO)
			sc_write(2, "sc_dup2 STDOUT close 1\n", WRITE_ERROR);
	}
	close(new_fd);
	ret_fd = dup2(old_fd, new_fd);
	if (ret_fd == -1)
		perror("sc_dup2");
	return (ret_fd);
}
