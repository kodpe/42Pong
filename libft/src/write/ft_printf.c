/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:05:59 by sloquet           #+#    #+#             */
/*   Updated: 2022/07/22 12:27:22 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "hsl_write.h"

static size_t	st_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	print_str(char *s, int fd)
{
	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(s, fd);
	return ((int)st_strlen(s));
}

static int	what_conv(char c, va_list *p, int fd)
{
	if (c == 's')
		return (print_str(va_arg(*p, char *), fd));
	else if (c == 'p')
		return (ft_putptr_fd(va_arg(*p, unsigned long), fd));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(*p, int), fd));
	else if (c == 'u')
		return (ft_putnbase(va_arg(*p, unsigned int), "0123456789", fd));
	else if (c == 'x')
		return (ft_putnbase(va_arg(*p, unsigned int), "0123456789abcdef", fd));
	else if (c == 'X')
		return (ft_putnbase(va_arg(*p, unsigned int), "0123456789ABCDEF", fd));
	else if (c == 'c')
		ft_putchar_fd(va_arg(*p, int), fd);
	else
		ft_putchar_fd(c, fd);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		i;
	int		nbytes;
	int		fd;

	fd = 1;
	i = 0;
	nbytes = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			nbytes += what_conv(format[i + 1], &params, 1);
			i++;
		}
		else
		{
			write(fd, &format[i], 1);
			nbytes++;
		}
		i++;
	}
	va_end(params);
	return (nbytes);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	params;
	int		i;
	int		nbytes;

	i = 0;
	nbytes = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			nbytes += what_conv(format[i + 1], &params, fd);
			i++;
		}
		else
		{
			write(fd, &format[i], 1);
			nbytes++;
		}
		i++;
	}
	va_end(params);
	return (nbytes);
}
