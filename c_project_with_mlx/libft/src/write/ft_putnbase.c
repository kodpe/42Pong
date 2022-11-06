/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:02:52 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 14:01:55 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_write.h"

static size_t	st_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*st_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

static int	ft_nbrlen_ul(unsigned long nbr, unsigned int base)
{
	int	i;

	i = 1;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

static int	ft_check_base(const char *base)
{
	if (st_strlen(base) < 2)
		return (0);
	if (st_strchr(base, '+') || st_strchr(base, '-'))
		return (0);
	while (*base)
	{
		if (st_strchr(base + 1, *base))
			return (0);
		base++;
	}
	return (1);
}

int	ft_putnbase(unsigned long nbr, const char *base, int fd)
{
	unsigned long	n;
	int				size;

	if (!ft_check_base(base))
		return (-1);
	n = (unsigned long)nbr;
	size = (unsigned long)st_strlen(base);
	if (n >= st_strlen(base))
		ft_putnbase(n / size, base, fd);
	write(fd, &base[n % size], 1);
	return (ft_nbrlen_ul(nbr, size));
}
/*
int	main(int ac, char **av)
{
	ft_printf("ac = %d\n", ac);
	if (ac != 3)
		return (0);
	for (int i = 0; i < 20; i++) {
		ft_putnbase(atoi(av[1]) + i, av[2], 1);
		write(1, "\n", 1);
	}
	return (0);
}
*/
