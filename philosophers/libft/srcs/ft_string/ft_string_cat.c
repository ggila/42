/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:55:39 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 20:56:59 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_str.h"

int			ft_string_cat(t_string *dst, const char *src)
{
	size_t	len;

	if (!src)
		return (0);
	len = ft_strlen(src);
	if (!dst || ft_string_resize(dst, dst->len + len) < 0)
		return (-1);
	ft_strcat(dst->str, src);
	dst->len += len;
	return (0);
}
