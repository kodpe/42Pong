/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ardup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:54:11 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/20 11:45:12 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

static size_t	arlen(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

static void	*free_new(char **new, int i)
{
	while (i >= 0)
	{
		free(new[i]);
		i--;
	}
	free(new);
	return (NULL);
}

char	**ft_ardup(char **array)
{
	char	**new;
	int		i;

	if (!array)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (arlen(array) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (array[i])
	{
		new[i] = ft_strdup(array[i]);
		if (!new)
			return (free_new(new, i - 1));
		i++;
	}
	new[i] = NULL;
	return (new);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**sp;
	char	**new;
	int		i;

	sp = ft_split("bonjour les amis", ' ');
	if (!sp)
		return (1);
	new = ft_ardup(sp);
	if (!new)
	{
		ft_arfree(sp);
		return (1);
	}
	if (new)
	{
		for (i = 0; new[i]; i++)
			printf("%d: [%s]\n", i, new[i]);
		printf("%d: [%p]\n", i, new[i]);
	}
	ft_arfree(new);
	ft_arfree(sp);
	return (0);
}
*/
