/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_ncat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:01:09 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 20:19:54 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_str.h"

int		ft_string_ncat(t_string *dst, const char *src, size_t n)
{
	size_t	len;

	if (!src)
		return (0);
	len = ft_strnlen(src, n);
	if (!dst || ft_string_resize(dst, dst->len + len) < 0)
		return (-1);
	ft_strncat(dst->str, src, len);
	dst->len += len;
	return (0);
}
