/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:13:54 by sloquet           #+#    #+#             */
/*   Updated: 2022/06/06 14:38:40 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_mem.h"

/**
 * secure calloc with error management
 **/
void	*ft_pcalloc(const size_t size, const char *error_msg)
{
	void	*p;

	p = malloc(size);
	if (!p)
	{
		perror(error_msg);
		return (NULL);
	}
	ft_bzero(p, size);
	return (p);
}
