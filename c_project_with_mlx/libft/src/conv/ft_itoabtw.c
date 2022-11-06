/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabtw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 08:53:11 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:40:22 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_conv.h"

char	*ft_itoabtw(char *left_str, int nbr, char *right_str)
{
	char	*nbr_str;
	char	*left;
	char	*complete;

	nbr_str = ft_itoa(nbr);
	if (!nbr_str)
		return (NULL);
	left = ft_strjoin(left_str, nbr_str);
	if (!left)
		return (NULL);
	free(nbr_str);
	complete = ft_strjoin(left, right_str);
	free(left);
	return (complete);
}
