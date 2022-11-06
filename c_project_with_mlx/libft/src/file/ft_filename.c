/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:03:07 by sloquet           #+#    #+#             */
/*   Updated: 2022/02/22 12:03:12 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_file.h"

#ifdef __linux__
# define PATH_SEPARATOR '/'
# define PATH_SEPARATOR_STR "/"
#elif _WIN32
# define PATH_SEPARATOR '\\'
# define PATH_SEPARATOR_STR "\\"
#else
# define PATH_SEPARATOR '?'
# define PATH_SEPARATOR_STR "_?_"
#endif

static int	unknown_separator(void)
{
	if (PATH_SEPARATOR == '?')
	{
		ft_putsnl_fd("ft_filename.c:22 ERR UNKNOWN PATH_SEPARATOR", 2);
		return (1);
	}
	return (0);
}

/**
 * return string contains filename from filepath
 * return null on error
 */
char	*ft_filename(const char *filepath)
{
	char	**splited;
	char	*name;
	int		i;

	if (unknown_separator())
		return (NULL);
	if (PATH_SEPARATOR == filepath[ft_strlen(filepath) - 1])
		return (NULL);
	splited = ft_split(filepath, PATH_SEPARATOR);
	if (!splited)
		return (NULL);
	i = 0;
	while (splited[i] && splited[i + 1])
		i++;
	name = ft_strdup(splited[i]);
	if (!name)
	{
		ft_arfree(splited);
		return (NULL);
	}
	ft_arfree(splited);
	return (name);
}
