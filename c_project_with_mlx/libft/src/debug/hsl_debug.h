/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_debug.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:56:26 by zsheep            #+#    #+#             */
/*   Updated: 2022/08/19 12:28:05 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_DEBUG_H
# define HSL_DEBUG_H

# include <stdio.h>
# include <stdlib.h>
# include "../write/hsl_write.h"
# include "../str/hsl_str.h"
# include "../conv/hsl_conv.h"

# define FI "FI N/A"
# define LN "LN N/A"

# ifdef __FILE__
#  undef FI
#  define FI __FILE__
# endif

# ifdef __LINE__
#  undef LN 
#  define LN __LINE__
# endif

/**
 *		dbg_ar.c
 */
void	dbg_ar(const char **array, const char *name);

/**
 *		debug_aux.c
 */
char	*dbg_display_file_range(char *filepath, int line, int range);
void	dbg_cmd(char *_FI, int _LN, int mark);
void	dbg_assert(int value, int correct_value);

/**
 *		debug_coffee.c
 */
void	dbs(char *_FI, int _LN);
void	dbe(char *_FI, int _LN);
void	db(char *_FI, int _LN, char *debug_msg);
void	db3(char *_FI, int _LN, char *debug_msg);
void	dbx(char *_FI, int _LN, char *debug_msg, int range);

/**
 *		debug_int.c
 */
void	dbv(char *_FI, int _LN, char *debug_msg, int variable);
void	dba(char *_FI, int _LN, int variable, int correct_value);

#endif /* HSL_DEBUG_H */
