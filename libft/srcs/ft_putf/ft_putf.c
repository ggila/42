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

void			ft_vputf_fd(int fd, const char *str, va_list ap)
{
	size_t		i;
	int			format[2];

	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		write(fd, str, i);
		str += i;
		if (*str == '%')
		{
			str++;
			str = putf_format_read(format, str);
			if (format[PUTF_CONVERSION] > 0)
				putf_putarg_fd(fd, format, ap);
		}
	}
	return ;
}

void			ft_putf_fd(int fd, const char *str, ...)
{
	va_list			ap;

	if (!str)
		return ;
	va_start(ap, str);
	ft_vputf_fd(fd, str, ap);
	va_end(ap);
	return ;
}

void			ft_vputf(const char *str, va_list ap)
{
	ft_vputf_fd(1, str, ap);
	return ;
}

void			ft_putf(const char *str, ...)
{
	va_list			ap;

	if (!str)
		return ;
	va_start(ap, str);
	ft_vputf(str, ap);
	va_end(ap);
	return ;
}
