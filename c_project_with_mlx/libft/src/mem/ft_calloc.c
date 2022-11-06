/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:10:42 by sloquet           #+#    #+#             */
/*   Updated: 2022/06/21 19:25:22 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_mem.h"

/**
 * ft_calloc allocate unused space for an array of nelem elements
 * each of whose size in bytes is elsize.
 * The space shall be initialized to all bits 0.
 */

void	*ft_calloc(size_t num)
{
	void	*p;

	p = malloc(num);
	if (!p)
		return (NULL);
	ft_bzero(p, num);
	return (p);
}
