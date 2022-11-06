/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:13:21 by sloquet           #+#    #+#             */
/*   Updated: 2022/03/17 17:14:48 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_file.h"

/**
 * return the nb of lines of the file,
 * -1 if the file don't exist
 */
int	ft_filelen(const char *filepath)
{
	char	*tmp;
	int		size;
	int		fd;

	tmp = NULL;
	size = 0;
	fd = open(filepath, O_RDONLY);
	if (0 > fd)
	{
		perror("ft_filelen");
		return (-1);
	}
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		free(tmp);
		size++;
	}
	close(fd);
	return (size);
}
