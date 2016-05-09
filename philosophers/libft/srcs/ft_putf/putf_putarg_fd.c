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

void		putf_putarg_fd(int fd, int format[], va_list ap)
{
	if (format[PUTF_CONVERSION] == 'i')
		return (putf_i(fd, format, ap));
	if (format[PUTF_CONVERSION] == 'u'
		|| format[PUTF_CONVERSION] == 'o'
		|| format[PUTF_CONVERSION] == 'x'
		|| format[PUTF_CONVERSION] == 'b')
		return (putf_u(fd, format, ap));
	if (format[PUTF_CONVERSION] == 'c')
		return (putf_c(fd, format, ap));
	if (format[PUTF_CONVERSION] == 's')
		return (putf_s(fd, format, ap));
	ft_putchar_fd(format[PUTF_CONVERSION], fd);
	return ;
}
