/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:55:39 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/12 22:51:46 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_str.h"
#include "ft_mem.h"

int			ft_string_insert(t_string *dst, size_t pos, char *str)
{
	size_t		len;

	len = ft_strlen(str);
	if (!dst || !str || ft_string_resize(dst, dst->len + len) < 0)
		return (-1);
	if (pos > dst->len)
		pos = dst->len;
	ft_memmove(dst->str + pos + len, dst->str + pos, dst->len - pos);
	ft_memmove(dst->str + pos, str, len);
	dst->len += len;
	dst->str[dst->len] = 0;
	return (0);
}
