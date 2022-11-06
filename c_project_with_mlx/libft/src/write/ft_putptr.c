/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:02:36 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/29 14:02:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_write.h"

#ifdef linux
# define OS_PTR_NULL "(nil)"
# define OS_PTR_NULL_SIZE 5
#else
# define OS_PTR_NULL "0x0"
# define OS_PTR_NULL_SIZE 3
#endif

int	ft_putptr(unsigned long ptr)
{
	if (!ptr)
	{
		ft_putstr(OS_PTR_NULL);
		return (OS_PTR_NULL_SIZE);
	}
	ft_putstr("0x");
	return (2 + ft_putnbase(ptr, "0123456789abcdef", 1));
}

int	ft_putptr_fd(unsigned long ptr, int fd)
{
	if (!ptr)
	{
		ft_putstr_fd(OS_PTR_NULL, fd);
		return (OS_PTR_NULL_SIZE);
	}
	ft_putstr_fd("0x", fd);
	return (2 + ft_putnbase(ptr, "0123456789abcdef", fd));
}
