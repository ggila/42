/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:29:15 by ggilaber          #+#    #+#             */
/*   Updated: 2015/08/24 19:17:19 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n && (*(unsigned char*)s1 == *(unsigned char*)s2))
	{
		n--;
		s1++;
		s2++;
	}
	if (!n)
		return (0);
	else
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
	return (0);
}
