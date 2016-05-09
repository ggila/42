/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:08:53 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 21:42:03 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	if (!src || !dst)
		return (NULL);
	if (src < dst)
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[len - 1 - i] = ((char *)src)[len - 1 - i];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
