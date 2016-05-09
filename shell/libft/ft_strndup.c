/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:12:55 by ggilaber          #+#    #+#             */
/*   Updated: 2015/08/24 19:19:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;

	if (!s1)
		return (NULL);
	if (!(dst = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(dst, s1, n);
	dst[n] = '\0';
	return (dst);
}
