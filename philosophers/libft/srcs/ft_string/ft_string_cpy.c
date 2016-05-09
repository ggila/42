/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:14:45 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 20:56:31 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_str.h"

int		ft_string_cpy(t_string *dst, const char *src)
{
	size_t	len;

	if (!src)
		return (ft_string_clear(dst));
	len = ft_strlen(src);
	if (!dst || (ft_string_resize(dst, len) < 0))
		return (-1);
	ft_strcpy(dst->str, src);
	dst->len = len;
	return (0);
}
