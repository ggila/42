/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:47:53 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 14:14:55 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_tab.h"
#include "ft_misc.h"

static size_t		ft_offset_nextblock_space(char const *s)
{
	size_t		j;

	j = 0;
	while (s[j] && ((ft_isspace(s[0]) && ft_isspace(s[j]))
		|| (!ft_isspace(s[0]) && !ft_isspace(s[j]))))
		j++;
	return (j);
}

static size_t		ft_getnbword_space(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		j = ft_offset_nextblock_space(s + i);
		if (!ft_isspace(s[i]))
			n++;
		i = i + j;
	}
	return (n);
}

char				**ft_strsplit_space(char const *s)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	n;

	if (!s || !(res = ft_tabnew(ft_getnbword_space(s))))
		return (NULL);
	i = 0;
	n = 0;
	while (s[i])
	{
		j = ft_offset_nextblock_space(s + i);
		if (!ft_isspace(s[i]))
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
