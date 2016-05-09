/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:31:29 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 12:50:30 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*res;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(res = ft_strnew(len)))
		return (NULL);
	len = 0;
	while (s[len])
	{
		res[len] = f(s[len]);
		len++;
	}
	return (res);
}
