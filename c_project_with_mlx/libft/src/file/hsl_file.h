/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:57:51 by zsheep            #+#    #+#             */
/*   Updated: 2022/03/17 17:14:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_FILE_H
# define HSL_FILE_H

# include <fcntl.h>
# include <stdio.h>
# include "../str/hsl_str.h"
# include "../write/hsl_write.h"

/**
 *      return the nb of lines of the file,
 *      -1 if the file don't exist
 */
int		ft_filelen(const char *filepath);

/**
 * 		ft_filename.c	
 * 		return string contains filename from filepath
 * 		return null on error
 */
char	*ft_filename(const char *filepath);

/**
 *      return the line n of the file,
 *      null if the line or the file don't exist
 */
char	*ft_gnln(const char *filepath, const int n);

/**
 *		ft_is_extension.c
 * 		return 1 when filepath match with extension
 * 		return 0 on wrong extension or if filename is only extension
 * 		dot '.' (or another custom) char must be included in extension
 */
int		ft_is_extension(const char *filepath, const char *extension);

#endif /* HSL_FILE_H */
