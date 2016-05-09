/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 14:44:47 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_set_flag(char c)
{
	if (c == 't')
		g_flag |= MASK_TOTAL;
	else if (c == 'f')
		g_flag |= MASK_FLAG;
	else if (c == 'd')
		g_flag |= MASK_DEBUG;
	else if (c == 'v')
		g_flag |= MASK_VISUAL;
	else
	{
		ft_putendl(USAGE);
		exit(OK);
	}
}

void	ft_get_opt(int *ac, char ***av)
{
	int		i;
	char	*str;

	g_flag = 0;
	str = (*av)[1];
	if (str[0] != '-')
		return ;
	else if (ft_strlen(str) >= 1)
	{
		i = 0;
		while (str[++i])
			ft_set_flag(str[i]);
		*ac -= 1;
	}
	else
	{
		ft_putendl(USAGE);
		exit(OK);
	}
	return ;
}
