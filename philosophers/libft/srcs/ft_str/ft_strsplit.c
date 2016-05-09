/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:47:53 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 14:14:47 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_tab.h"

static size_t		ft_offset_nextblock(char const *s, char c)
{
	size_t		j;

	j = 0;
	while (s[j] && ((s[0] == c && s[j] == c) || (s[0] != c && s[j] != c)))
		j++;
	return (j);
}

static size_t		ft_getnbword(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		j = ft_offset_nextblock(s + i, c);
		if (s[i] != c)
			n++;
		i = i + j;
	}
	return (n);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	n;

	if (!s || !(res = ft_tabnew(ft_getnbword(s, c))))
		return (NULL);
	i = 0;
	n = 0;
	while (s[i])
	{
		j = ft_offset_nextblock(s + i, c);
		if (s[i] != c)
		{
			if (!(res[n++] = ft_strsub(s, i, j)))
			{
				ft_tabdel(&res);
				return (NULL);
			}
		}
		i += j;
	}
	return (res);
}
