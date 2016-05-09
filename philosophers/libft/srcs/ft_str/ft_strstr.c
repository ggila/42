/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:09:16 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 12:50:25 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!(*s2))
		return ((char *)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j])
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
