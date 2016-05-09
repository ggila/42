/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:10:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 21:02:48 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_str.h"

t_string		*ft_string_sub(char const *src, size_t n)
{
	t_string	*res;
	size_t		len;

	len = ft_strnlen(src, n);
	if (!(res = ft_string_new(len)))
		return (0);
	ft_strncpy(res->str, src, len);
	res->str[len] = 0;
	res->len = len;
	return (res);
}
