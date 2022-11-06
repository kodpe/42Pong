/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:31:55 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/22 11:40:16 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_file.h"

/**
 * return 1 when filepath match with extension
 * return 0 on wrong extension or if filename is only extension
 */
int	ft_is_extension(const char *filepath, const char *extension)
{
	char	*name;
	char	*comparefrom;
	size_t	extlen;

	name = ft_filename(filepath);
	if (!name)
		return (0);
	extlen = ft_strlen(extension);
	if (ft_strlen(name) <= extlen)
	{
		free(name);
		return (0);
	}
	comparefrom = &name[ft_strlen(name) - extlen];
	if (ft_strncmp(comparefrom, extension, extlen))
	{
		free(name);
		return (0);
	}
	free(name);
	return (1);
}
