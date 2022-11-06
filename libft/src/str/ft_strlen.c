/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:11:42 by sloquet           #+#    #+#             */
/*   Updated: 2022/06/28 11:28:34 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 * ft_strlen calculates the length of the string pointed to by s,
 * excluding the terminating null byte ('\0').
 */

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlen_sc(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
#include <string.h>
#include <stdio.h>

void	ft_test(char *s)
{
	if (ft_strlen(s) == strlen(s))
		ft_printf("OK: ft_strlen\n");
	else
		ft_printf("KO: ft_strlen\n");
}

int	main(void)
{
	ft_test("test");
	ft_test("");
	ft_test("k;fl krv;lk; ev; kr4566#$^&* bkv;k3ihgoi io30@#$30948\n\n");
}
*/
