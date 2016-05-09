/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:29:11 by jsaglio           #+#    #+#             */
/*   Updated: 2014/12/16 16:29:16 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putf_hidden.h"

static t_uc		putf_getarg_c(va_list ap, int format[])
{
	UNUSED(format);
	return ((t_uc)va_arg(ap, t_ulli));
}

void			putf_c(int fd, int format[], va_list ap)
{
	t_uc		c;

	c = putf_getarg_c(ap, format);
	ft_putchar_fd(c, fd);
	return ;
}
