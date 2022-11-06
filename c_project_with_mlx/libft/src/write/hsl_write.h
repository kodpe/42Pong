/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_write.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:18:29 by zsheep            #+#    #+#             */
/*   Updated: 2022/07/24 18:11:41 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_WRITE_H
# define HSL_WRITE_H

# define WRITE_ERROR "write error"

# include <unistd.h>

/**
 * 		sc_write.c
 */
int		sc_write(const int fd, const char *str, const char *error_msg);

/**
 *		ft_printf.c
 */
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);

/**
 *		ft_putarray.c
 */
void	ft_putarray(char **array);
void	ft_putarray_fd(char **array, int fd);

/**
 *		ft_putchar.c
 */
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);

/**
 *		ft_putnbase.c
 */
int		ft_putnbase(unsigned long nbr, const char *base, int fd);

/**
 *		ft_putnbr.c
 */
void	ft_putnbr(int n);
int		ft_putnbr_fd(int n, int fd);

/**
 *		ft_putnl.c
 */
void	ft_putnl(void);
void	ft_putnl_fd(int fd);

/**
 *		ft_putptr.c
 */
int		ft_putptr(unsigned long ptr);
int		ft_putptr_fd(unsigned long ptr, int fd);

/**
 *		ft_putstr.c
 */
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putsnl(const char *s);
void	ft_putsnl_fd(const char *s, int fd);

/**
 *		ft_putx.c
 */
void	ft_putx_fd(int fd, int n, char *s);
void	ft_putxnl_fd(int fd, int n, char *s);

#endif /* HSL_WRITE_H */
