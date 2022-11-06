/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:01:42 by zsheep            #+#    #+#             */
/*   Updated: 2022/07/29 20:55:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_STR_H
# define HSL_STR_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../char/hsl_char.h"

/**
 *		ft_arfree.c
 */
int		ft_arfree(char **array);

/**
 *		ft_arsize.c
 */
size_t	ft_ar_size(char **ar);

/**
 *		ft_arlen.c
 */
int		ft_arlen(char **array);
int		ft_arlen_n(char **array);

/**
 * 		ft_close_gnl.c
 */
void	ft_close_gnl(int fd);

/**
 * 		ft_contains_only.c
 */
int		ft_contains_only(const char c, const char *str);

/**
 *		ft_split.c
 */
char	**ft_split(const char *s, char c);

/**
 *		ft_strchr.c
 */
char	*ft_strchr(const char *s, int c);

/**
 *		ft_strcmp.c
 */
int		ft_strcmp(char *s1, char *s2);

/**
 *		ft_strcpy.c
 */
char	*ft_strcpy(char *dest, const char *src);

/**
 *		ft_strdup.c
 */
char	*ft_strdup(const char *src);
char	*ft_strldup(const char *src, size_t size);

/**
 *		ft_striteri.c
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 *		ft_strjoin.c
 */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjointri(char const *s1, char const *s2, char const *s3);
// char	*ft_strjoin_sc(char const *s1, char const *s2);
// char	*ft_strjointri_sc(char const *s1, char const *s2, char const *s3);

/**
 *		ft_strlcat.c
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 *		ft_strlcpy.c
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 *		ft_strlen.c
 */
size_t	ft_strlen(const char *str);
size_t	ft_strlen_sc(const char *str);

/**
 *		ft_strmapi.c
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 *		ft_strncmp.c
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp_to_lower(char *s1, char *s2);

/**
 *		ft_strnstr.c
 */
char	*ft_strnstr(const char *big, const char *sub, size_t len);
char	*ft_strnstr2(const char *big, const char *sub, size_t len);
char	*ft_strnrstr(const char *big, const char *sub, size_t len);

/**
 *		ft_strrchr.c
 */
char	*ft_strrchr(const char *s, int c);

/**
 *		ft_strtolower.c
 */
char	*ft_strtolower(char *str);

/**
 *		ft_strtoupper.c
 */
char	*ft_strtoupper(char *str);

/**
 *		ft_strtrim.c
 */
char	*ft_strtrim(const char *s1, const char *set);

/**
 *		ft_substr.c
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 *		get_next_line.c
 */
char	*get_next_line(int fd);
char	*get_next_line_2(int fd, int *ret);

#endif /* HSL_STR_H */
