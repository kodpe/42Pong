/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:18:28 by zsheep            #+#    #+#             */
/*   Updated: 2022/02/01 12:18:28 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_COLOR_H
# define HSL_COLOR_H

# include <unistd.h>
# include "../str/hsl_str.h"

/**
 *		color_cool.c
 */
void	c_clbool(int x);
void	c_clboolsp(int x, char *true_color, char *false_color);
void	c_clscale(int x, int max);
void	c_clrainbow(char *str);

/**
 *		color_palette_bwgr.c
 */
void	c_black(void);
void	c_white(void);
void	c_green(void);
void	c_red(void);

/**
 *		color_palette_cbym.c
 */
void	c_cyan(void);
void	c_blue(void);
void	c_yellow(void);
void	c_magenta(void);

/**
 *		color_palette_format.c
 */
void	c_reset(void);
void	c_bold(void);
void	c_unline(void);
void	c_invert(void);

#endif /* HSL_COLOR_H */
