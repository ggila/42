/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 00:38:49 by ggilaber          #+#    #+#             */
/*   Updated: 2015/08/24 19:19:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	if (!s)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return (&(((unsigned char*)s)[i]));
	}
	return (NULL);
}
