/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_cool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 06:35:30 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:46:04 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_color.h"

void	c_clbool(int x)
{
	if (x)
		c_green();
	else
		c_red();
}

void	c_clboolsp(int x, char *true_color, char *false_color)
{
	if (x)
		write(1, true_color, ft_strlen(true_color));
	else
		write(1, false_color, ft_strlen(false_color));
}

void	c_clscale(int x, int max)
{
	if (x > max)
		c_red();
	else if (x > 4 * max / 5)
		c_green();
	else if (x > 3 * max / 5)
		c_yellow();
	else if (x > 2 * max / 5)
		c_blue();
	else if (x > 1 * max / 5)
		c_magenta();
	else if (x > 0)
		c_cyan();
	else if (x < 0)
		c_white();
}

void	c_clrainbow(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 6 == 0)
			c_red();
		if (i % 6 == 1)
			c_yellow();
		if (i % 6 == 2)
			c_green();
		if (i % 6 == 3)
			c_cyan();
		if (i % 6 == 4)
			c_blue();
		if (i % 6 == 5)
			c_magenta();
		write(1, &str[i], 1);
		i++;
	}
}
