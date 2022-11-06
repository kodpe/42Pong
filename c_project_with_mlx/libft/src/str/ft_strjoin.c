/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:04:44 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/29 20:55:51 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 * Allocates (with malloc(3)) and returns a new
 * string, which is the result of the concatenation
 * of ’s1’ and ’s2’.
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	k;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = 0;
	return (str);
}

char	*ft_strjointri(char const *s1, char const *s2, char const *s3)
{
	char	*tmp;
	char	*complete;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	complete = ft_strjoin(tmp, s3);
	free(tmp);
	tmp = NULL;
	return (complete);
}
/*
char	*ft_strjoin_sc(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	else
		return (ft_strjoin(s1, s2));
}

char	*ft_strjointri_sc(char const *s1, char const *s2, char const *s3)
{
	char	*tmp;
	char	*complete;

	tmp = ft_strjoin_sc(s1, s2);
	complete = ft_strjoin_sc(tmp, s3);
	free(tmp);
	tmp = NULL;
	return (complete);
}
*/

/*
test char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1) + 1;
	ls2 = ft_strlen(s2);
	str = (char *)malloc(ls1 + ls2);
	if (!str)
		return (NULL);
	str[0] = 0;
	ft_strlcat(str, s1, ls1);
	ft_strlcat(str, s2, ls1 + ls2);
	return (str);
}*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_test(const char *s1, const char *s2, const char *reference)
{
	char	*joined_str;
	int		result;

	joined_str = ft_strjoin(s1, s2);
	if (!joined_str)
	{
		ft_printf("Memory allocation error\n");
		exit(42);
	}
	result = strcmp(joined_str, reference);
	free(joined_str);
	return (result);
}

static int	ft(const char *s1, const char *s2, const char *s3, const char *ref)
{
	char	*joined_str;
	char	*nested_str;
	int		result;

	joined_str = ft_strjoin(s1, s2);
	if (!joined_str)
	{
		ft_printf("Memory allocation error\n");
		exit(42);
	}
	nested_str = ft_strjoin(joined_str, s3);
	if (!nested_str)
	{
		ft_printf("Memory allocation error\n");
		exit(42);
	}
	result = strcmp(nested_str, ref);
	free(joined_str);
	free(nested_str);
	return (result);
}

int	main(void)
{
	if (ft_test("", "", "")
		|| ft_test("ft_", "", "ft_")
		|| ft_test("", "strjoin", "strjoin")
		|| ft_test("ft_", "strjoin", "ft_strjoin")
		|| ft("OK: ", "ft_", "strjoin", "OK: ft_strjoin"))
	{
		ft_printf("KO: ft_strjoin\n");
		return (1);
	}
	ft_printf("OK: ft_strjoin\n");
	return (0);
}
*/
