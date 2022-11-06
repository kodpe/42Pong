/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:05:43 by sloquet           #+#    #+#             */
/*   Updated: 2022/08/19 11:58:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hsl_write.h"

int	main(int ac, char **av)
{
	(void)ac;
	ft_putarray(av);
	ft_printf("\nThe cow jumped over the moon.\n");
	ft_putarray_fd(av, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbase(42, "01", 1);
	ft_putnl();
	ft_putnbr(42);
	ft_putnbr_fd(42, 1);
	ft_putnl_fd(1);
	ft_putptr(42);
	ft_putchar('\n');
	ft_putptr_fd(4242, 1);
	ft_putstr("\nThe cow jumped over the moon.\n");
	ft_putstr_fd("The cow jumped over the moon.\n", 1);
	ft_putsnl("The cow jumped over the moon.");
	ft_putsnl_fd("The cow jumped over the moon.", 1);
	ft_putx_fd(2, 3, "*");
	ft_putxnl_fd(2, 3, "-");
	return (0);
}
