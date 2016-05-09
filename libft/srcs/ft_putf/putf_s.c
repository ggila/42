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

static char		*putf_getarg_s(va_list ap, int format[])
{
	UNUSED(format);
	return (va_arg(ap, char *));
}

void			putf_s(int fd, int format[], va_list ap)
{
	char		*str;

	str = putf_getarg_s(ap, format);
	ft_putstr_fd(str, fd);
	return ;
}
