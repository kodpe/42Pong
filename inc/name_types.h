/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:44:50 by sloquet           #+#    #+#             */
/*   Updated: 2022/09/17 02:36:44 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAME_TYPES_H
# define NAME_TYPES_H

# include "name.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct s_rt
{
	void	*mlx_id;
	void	*win;
	int		win_x;
	int		win_y;
	void	*img_id;
	char	*img_addr;
	int		img_endian;
	int		bits_per_pixel;
	int		line_length;
	t_point	center;
}	t_rt;

#endif /* NAME_TYPES_H */
