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

static t_lli	putf_getarg_i(va_list ap, int format[])
{
	t_lli		n;

	n = 0;
	if (format[PUTF_MODIF] == none)
		n = (t_lli)(t_i)va_arg(ap, t_lli);
	else if (format[PUTF_MODIF] == hh)
		n = (t_lli)(t_c)va_arg(ap, t_lli);
	else if (format[PUTF_MODIF] == h)
		n = (t_lli)(t_si)va_arg(ap, t_lli);
	else if (format[PUTF_MODIF] == l)
		n = (t_lli)(t_li)va_arg(ap, t_lli);
	else if (format[PUTF_MODIF] == ll)
		n = (t_lli)(t_lli)va_arg(ap, t_lli);
	return (n);
}

void			putf_i(int fd, int format[], va_list ap)
{
	t_lli		n;

	n = putf_getarg_i(ap, format);
	ft_putnbr_fd(n, fd);
	return ;
}
