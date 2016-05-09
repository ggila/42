/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:10:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 12:50:24 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s || (len + start > ft_strlen(s)))
		return (NULL);
	if (!(res = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}
