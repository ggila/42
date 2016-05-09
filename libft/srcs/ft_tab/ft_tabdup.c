/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 16:44:51 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 14:14:20 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tab.h"
#include "ft_str.h"

char	**ft_tabdup(char **src)
{
	size_t	i;
	char	**dst;

	if (!src || !(dst = ft_tabnew(ft_tablen(src))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		if (!(dst[i] = ft_strdup(src[i])))
		{
			ft_tabdel(&dst);
			return (NULL);
		}
		i++;
	}
	return (dst);
}
