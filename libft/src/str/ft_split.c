/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:42:20 by sloquet           #+#    #+#             */
/*   Updated: 2022/03/21 13:28:26 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 * Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must be
 * ended by a NULL pointer.
 */

static int	ft_freeall(char **split, int wd)
{
	int	i;

	while (i < wd)
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
	return (0);
}

static char	*ft_strxcpy(char *wd, char const *s, int start, int wd_len)
{
	int	i;

	i = 0;
	while (i < wd_len)
	{
		wd[i] = s[start + i];
		i++;
	}
	wd[i] = 0;
	return (wd);
}

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] == 0)
			break ;
		while (str[i] != c && str[i])
			i++;
		count++;
	}
	return (count);
}

static int	ft_get_words(char **split, const char *s, char c, int wd_count)
{
	int	i;
	int	wd;
	int	wd_len;

	i = 0;
	wd = 0;
	while (wd < wd_count)
	{
		wd_len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			wd_len++;
		}
		split[wd] = (char *)malloc(sizeof(char) * (wd_len + 1));
		if (!split[wd])
			return (ft_freeall(split, wd));
		ft_strxcpy(split[wd], s, i - wd_len, wd_len);
		wd++;
	}
	split[wd_count] = 0;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char		**split;
	int			wd_count;

	if (!s)
		return (NULL);
	wd_count = ft_count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (wd_count + 1));
	if (!split)
		return (NULL);
	if (!ft_get_words(split, s, c, wd_count))
		return (NULL);
	return (split);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	free_all(char **memory, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(memory[i++]);
	free(memory);
}

static size_t	arrlen(char **arr)
{
	size_t	len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

static int	ft_test(const char *str, const char chr, char **ref)
{
	char	**splits;
	size_t	i;
	size_t	count;

	count = arrlen(ref);
	splits = ft_split(str, chr);
	if (!splits)
	{
		ft_printf("Memory allocation error.\n");
		return (1);
	}
	i = 0;
	while (splits[i] && ref[i])
	{
		if (strcmp(splits[i], ref[i]))
		{
			free_all(splits, count);
			return (1);
		}
		i++;
	}
	if (splits[i] && splits[i] != ref[i])
	{
		free_all(splits, count);
		return (1);
	}
	else if (splits[0])
		free_all(splits, count);
	else
		free(splits);
	return (0);
}

static int	ft_test_either(const char *str, const char chr, char **ref1,
	char **ref2)
{
	return (!(!ft_test(str, chr, ref1)
			|| !ft_test(str, chr, ref2)));
}

int	main(void)
{
	if (ft_test_either("", '*',
			(char *[]){"", NULL}, (char *[]){NULL})
		|| ft_test_either("******", '*',
			(char *[]){"", NULL}, (char *[]){NULL})
		|| ft_test("***a***", '*',
			(char *[]){"a", NULL})
		|| ft_test("*hello*fellow***students*", '*',
			(char *[]){"hello", "fellow", "students", NULL}))
	{
		ft_printf("KO: ft_split\n");
		return (1);
	}
	ft_printf("OK: ft_split\n");
	return (0);
}
*/
