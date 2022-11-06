/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:06:27 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:49:51 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_char.h"

/**
 * ft_isascii test whether c is a 7-bit US-ASCII character code.
 */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
