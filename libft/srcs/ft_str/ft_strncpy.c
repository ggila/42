/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:21:35 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 12:50:29 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	if (!dst || !src)
		return (NULL);
	src_len = ft_strlen(src);
	i = 0;
	while (i < n)
	{
		dst[i] = (i < src_len) ? src[i] : '\0';
		i++;
	}
	return (dst);
}
