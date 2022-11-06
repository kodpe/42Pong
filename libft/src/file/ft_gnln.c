/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnln.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:10:08 by sloquet           #+#    #+#             */
/*   Updated: 2022/03/17 17:11:52 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_file.h"

/**
 * return the line n of the file,
 * null if the line or the file don't exist
 */
char	*ft_gnln(const char *filepath, const int n)
{
	char	*tmp;
	int		fd;
	int		i;

	if (n < 1)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (0 > fd)
	{
		perror("ft_gnln");
		return (NULL);
	}
	tmp = NULL;
	i = 1;
	while (i <= n)
	{
		tmp = get_next_line(fd);
		if (!tmp || i == n)
			break ;
		free(tmp);
		i++;
	}
	ft_close_gnl(fd);
	close(fd);
	return (tmp);
}
