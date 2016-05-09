/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_explode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:48:32 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

char	***ft_cmd_explode(char *cmd)
{
	char	***new;
	char	**s;
	int		i;
	int		nb;

	if ((s = ft_strsplit(cmd, '|')) == NULL)
		ft_error("malloc failed (ft_cmd_explode)");
	nb = ft_strstrlen(s);
	if (!(new = (char***)malloc(sizeof(char**) * (nb + 1))))
		ft_error("malloc failed (ft_cmd_explode)");
	new[nb] = NULL;
	i = 0;
	while (i < nb)
	{
		if (!(new[i] = ft_strsplit(s[i], ' ')))
			ft_error("malloc failed (ft_cmd_explode)");
		i++;
	}
	return (new);
}
