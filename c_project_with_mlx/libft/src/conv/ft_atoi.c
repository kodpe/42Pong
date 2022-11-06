/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:04:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 15:39:03 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_conv.h"

/**
 * ft_atoi converts the initial portion of the string pointed to by str to int.
 */

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	return (nbr * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	test(char *n)
{
	int		i1;
	int		i2;

	i1 = atoi(n);
	i2 = ft_atoi(n);
	if (0)
		ft_printf("%d %d\n", i1, i2);
	return (i1 == i2);
}

int	main(void)
{
	if (!test("0")
		|| !test("-0")
		|| !test("+0")
		|| !test("-")
		|| !test("+")
		|| !test("a")
		|| !test("+a")
		|| !test("-b")
		|| !test("7")
		|| !test("+7a3")
		|| !test("\t\n\r\v\f  469 \n")
		|| !test("-6O40")
		|| !test("++10")
		|| !test("--10")
		|| !test("2147483647")
		|| !test("-2147483648")
		|| !test("1000000000000")
		|| !test("-1000000000000"))
	{
		ft_printf("KO: ft_atoi\n");
		return (1);
	}
	ft_printf("OK: ft_atoi\n");
	if (!ft_test("9999999999999999999999999999999998"))
		ft_printf("hummm \n");
	ft_printf("or %d\n", atoi("9999999999999999999999999999999998"));
	ft_printf("ft %d\n", ft_atoi("9999999999999999999999999999999998"));
	ft_printf("or %d\n", atoi("1234567891113151719"));
	ft_printf("ft %d\n", ft_atoi("1234567891113151719"));
	ft_printf("or %d\n", atoi("9223372036854775808"));
	ft_printf("ft %d\n", ft_atoi("9223372036854775808"));
	ft_printf("or %d\n", atoi("-2147483649"));
	ft_printf("ft %d\n", ft_atoi("-2147483649"));
	return (0);
}
*/
