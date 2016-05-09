/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:46:04 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/13 16:12:13 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_str.h"
#include "ft_mem.h"

int			ft_string_resize(t_string *str, size_t size)
{
	size_t		capacity_new;
	char		*save;

	if (size < str->len)
	{
		str->len = size;
		str->str[size] = 0;
		return (0);
	}
	size += 1;
	capacity_new = str->capacity;
	while (capacity_new < size)
		capacity_new <<= 1;
	save = str->str;
	if (!(str->str = FT_ZMALLOC(char, capacity_new)))
		return (-1);
	ft_strcpy(str->str, save);
	str->capacity = capacity_new;
	free(save);
	return (0);
}
