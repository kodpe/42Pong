/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette_cbym.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 05:39:12 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:45:42 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_color.h"

#define CYAN "\e[36m"
#define BLUE "\e[34m"
#define YELLOW "\e[33m"
#define MAGENTA "\e[35m"

void	c_cyan(void)
{
	write(1, CYAN, ft_strlen(CYAN));
}

void	c_blue(void)
{
	write(1, BLUE, ft_strlen(BLUE));
}

void	c_yellow(void)
{
	write(1, YELLOW, ft_strlen(YELLOW));
}

void	c_magenta(void)
{
	write(1, MAGENTA, ft_strlen(MAGENTA));
}
