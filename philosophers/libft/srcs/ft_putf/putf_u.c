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

static t_ulli		putf_getarg_u(va_list ap, int format[])
{
	t_ulli		n;

	n = 0;
	if (format[PUTF_MODIF] == none)
		n = (t_ulli)(t_ui)va_arg(ap, t_ulli);
	else if (format[PUTF_MODIF] == hh)
		n = (t_ulli)(t_uc)va_arg(ap, t_ulli);
	else if (format[PUTF_MODIF] == h)
		n = (t_ulli)(t_usi)va_arg(ap, t_ulli);
	else if (format[PUTF_MODIF] == l)
		n = (t_ulli)(t_uli)va_arg(ap, t_ulli);
	else if (format[PUTF_MODIF] == ll)
		n = (t_ulli)(t_ulli)va_arg(ap, t_ulli);
	return (n);
}

void				putf_u(int fd, int format[], va_list ap)
{
	t_ulli		n;

	n = putf_getarg_u(ap, format);
	if (format[PUTF_CONVERSION] == 'b')
		ft_putulli_base_fd(n, "01", fd);
	else if (format[PUTF_CONVERSION] == 'o')
		ft_putulli_base_fd(n, "01234567", fd);
	else if (format[PUTF_CONVERSION] == 'x')
		ft_putulli_base_fd(n, "0123456789abcdef", fd);
	else
		ft_putulli_base_fd(n, "0123456789", fd);
	return ;
}
