/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putf_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:29:11 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 14:18:40 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putf_hidden.h"

static char const	*putf_format_read_mod(int format[], char const *str)
{
	format[PUTF_MODIF] = none;
	if (*str == 'h')
	{
		str++;
		if (*str == 'h')
		{
			format[PUTF_MODIF] = hh;
			return (++str);
		}
		format[PUTF_MODIF] = h;
		return (str);
	}
	if (*str == 'l')
	{
		str++;
		if (*str == 'l')
		{
			format[PUTF_MODIF] = ll;
			return (++str);
		}
		format[PUTF_MODIF] = l;
		return (str);
	}
	return (str);
}

char const			*putf_format_read(int format[], char const *str)
{
	str = putf_format_read_mod(format, str);
	format[PUTF_CONVERSION] = *str;
	return (format[PUTF_CONVERSION] ? (str + 1) : str);
}
