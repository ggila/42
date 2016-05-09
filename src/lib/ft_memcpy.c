/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 03:29:09 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/01 14:41:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!src || !dst)
		return (NULL);
	i = 0;
	while (i < n / 8)
	{
		*((long unsigned int*)dst + i) = *((long unsigned int*)src + i);
		i += 8;
	}
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		++i;
	}
	return (dst);
}
