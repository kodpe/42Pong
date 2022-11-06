/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:19:28 by zsheep            #+#    #+#             */
/*   Updated: 2022/02/06 12:19:28 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_IO_H
# define HSL_IO_H

# include <unistd.h>
# include <stdio.h>

# include "../write/hsl_write.h"
# define SHOW_IO 0

/**
 * 		sc_close.c
 */
int		sc_close_std(int fd);
int		sc_close(int *fd);
void	sc_2close(int *fd1, int *fd2);
void	sc_3close(int *fd1, int *fd2, int *fd3);

/**
 *		sc_dup.c
 */
int		sc_dup(int old_fd);

/**
 *		sc_dup2.c
 */
int		sc_dup2(int old_fd, int new_fd);

/**
 * 		unlink_sc.c
 */
int		unlink_sc(char *str);

#endif /* HSL_IO_H */
