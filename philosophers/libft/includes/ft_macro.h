/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:31:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 12:32:16 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACRO_H
# define FT_MACRO_H

# define UNUSED(X)					((void)X)

# define TXT_DFLT 					"\e[0m"
# define TXT_B		 				"\e[1m"
# define TXT_U						"\e[4m"
# define TXT_BLACK 					"\e[30m"
# define TXT_RED 					"\e[31m"
# define TXT_GREEN 					"\e[32m"
# define TXT_YELLOW 				"\e[33m"
# define TXT_BLUE 					"\e[34m"
# define TXT_MAGENTA 				"\e[35m"
# define TXT_CYAN					"\e[36m"
# define TXT_GREY 					"\e[37m"

# define FLAG_GET(F, M)				(!!((F) & (M)))
# define FLAG_SET(F, M)				((F) |= (M))
# define FLAG_UNSET(F, M)			((F) &= ~(M))
# define FLAG_TOGGLE(F, M)			((F) ^= (M))

# define ABS(x) 					(((x) > 0) ? (x) : -(x))
# define MIN(x, y)					(((x) > (y)) ? (y) : (x))
# define MAX(x, y)					(((x) > (y)) ? (x) : (y))

# define OFFSETOF(st, m) 			((size_t)(&(((st*)0)->m)))
# define CONTAINEROF(ptr, st, m)	((st*)((char*)(ptr) - OFFSETOF(st,m)))

#endif
