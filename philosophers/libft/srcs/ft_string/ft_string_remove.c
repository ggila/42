/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:55:39 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/12 22:59:19 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"

int			ft_string_remove(t_string *dst, size_t pos, size_t n)
{
	if (!dst || (pos >= dst->len) || !n)
		return (-1);
	if (pos + n > dst->len)
		n = dst->len - pos;
	ft_memmove(dst->str + pos, dst->str + pos + n, dst->len - (pos + n));
	dst->len -= n;
	dst->str[dst->len] = 0;
	return (0);
}
