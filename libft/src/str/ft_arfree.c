/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:52:16 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/22 11:58:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 *  free char**
 * 	0 on success
 * 	-1 if array == NULL
 */
int	ft_arfree(char **array)
{
	int	i;

	if (!array)
		return (-1);
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
