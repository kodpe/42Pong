/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_box.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:17:24 by zsheep            #+#    #+#             */
/*   Updated: 2022/02/01 12:17:24 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_BOX_H
# define HSL_BOX_H

# include <stdlib.h>
# include "../write/hsl_write.h"

/**
 *		ft_box_del.c
 */
void	ft_box_del(char ***box);

/**
 *		ft_box_new.c
 */
char	***ft_box_new(const int x, const int y, const int z);

/**
 *		ft_box_show.c
 */
void	ft_box_show(char ***box);

/**
 *		ft_box_xlen.c
 */
size_t	ft_box_xlen(char ***box);

/**
 *		ft_box_ylen.c
 */
size_t	ft_box_ylen(char ***box);

/**
 *		ft_box_zlen.c
 */
size_t	ft_box_zlen(char ***box);

#endif /* HSL_BOX_H */
