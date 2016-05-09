/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_ncpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:21:35 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 20:56:35 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_str.h"

int			ft_string_ncpy(t_string *dst, const char *src, size_t n)
{
	size_t	len;

	if (!src)
		return (ft_string_clear(dst));
	len = ft_strnlen(src, n);
	if (!dst || (ft_string_resize(dst, len) < 0))
		return (-1);
	ft_strncpy(dst->str, src, len);
	dst->str[len] = 0;
	dst->len = len;
	return (0);
}
