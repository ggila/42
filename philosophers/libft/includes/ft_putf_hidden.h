/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:30:29 by jsaglio           #+#    #+#             */
/*   Updated: 2014/12/16 16:31:31 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTF_HIDDEN_H
# define FT_PUTF_HIDDEN_H

# include "ft_macro.h"
# include "ft_typedef.h"
# include "ft_put.h"

# include <stdarg.h>

# define PUTF_CONVERSION		0
# define PUTF_MODIF				1

enum	e_putf_modif
{
	none = 0,
	hh,
	h,
	l,
	ll,
};

char const		*putf_format_read(int format[], char const *str);
void			putf_putarg_fd(int fd, int format[], va_list ap);

void			putf_c(int fd, int format[], va_list ap);
void			putf_s(int fd, int format[], va_list ap);
void			putf_i(int fd, int format[], va_list ap);
void			putf_u(int fd, int format[], va_list ap);

#endif
