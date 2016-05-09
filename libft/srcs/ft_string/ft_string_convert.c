/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:54:39 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/14 16:39:32 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_str.h"

t_string	*ft_string_convert(const char *src)
{
	t_string	*res;
	size_t		len;

	len = ft_strlen(src);
	if (!(res = ft_string_new(len)))
		return (0);
	ft_strcpy(res->str, src);
	res->len = len;
	return (res);
}
