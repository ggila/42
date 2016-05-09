/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:29:44 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 19:56:16 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"

t_string		*ft_string_new(size_t size)
{
	t_string	*res;
	size_t		capacity;

	size += 1;
	capacity = T_STRING_DFLT_CAP;
	while (capacity < size)
		capacity <<= 1;
	if (!(res = FT_ZMALLOC(t_string, 1))
		|| !(res->str = FT_ZMALLOC(char, capacity)))
	{
		ft_string_del(&res);
		return (NULL);
	}
	res->len = 0;
	res->capacity = capacity;
	return (res);
}
