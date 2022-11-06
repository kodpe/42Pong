/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette_bwgr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 05:39:31 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:45:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_color.h"

#define BLACK "\e[30m"
#define WHITE "\e[37m"
#define GREEN "\e[32m"
#define RED "\e[31m"

void	c_black(void)
{
	write(1, BLACK, ft_strlen(BLACK));
}

void	c_white(void)
{
	write(1, WHITE, ft_strlen(WHITE));
}

void	c_green(void)
{
	write(1, GREEN, ft_strlen(GREEN));
}

void	c_red(void)
{
	write(1, RED, ft_strlen(RED));
}
