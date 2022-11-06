/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 05:39:36 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:45:33 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_color.h"

#define CL_NORMAL "\e[0m"
#define CL_BOLD "\e[1m"
#define CL_UNLINE "\e[4m"
#define CL_INVERT "\e[7m"

void	c_reset(void)
{
	write(1, CL_NORMAL, ft_strlen(CL_NORMAL));
}

void	c_bold(void)
{
	write(1, CL_BOLD, ft_strlen(CL_BOLD));
}

void	c_unline(void)
{
	write(1, CL_UNLINE, ft_strlen(CL_UNLINE));
}

void	c_invert(void)
{
	write(1, CL_INVERT, ft_strlen(CL_INVERT));
}
