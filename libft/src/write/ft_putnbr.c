/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:29:34 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 14:02:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_write.h"

void	ft_putnbr(int n)
{
	if (n >= 0)
	{
		if (n > 9)
		{
			ft_putnbr(n / 10);
		}
		ft_putchar(n % 10 + 48);
	}
	else if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
}

/**
 * Outputs the integer ’n’ to the given file descriptor.
 * return n character printed
 */
static long	st_abs(long n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static int	st_nbrlen(long nbr, int base)
{
	int	i;

	i = 1;
	if (nbr < 0)
		i++;
	while (st_abs(nbr) >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	nbr;

	nbr = n;
	if (n >= 0)
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	return (st_nbrlen(nbr, 10));
}
