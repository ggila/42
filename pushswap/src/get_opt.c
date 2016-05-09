/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 14:44:47 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:26:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_check_opt(char ***av)
{
	while (***av)
	{
		if (ft_strchr("vtnib", ***av))
		{
			if (***av == 'v')
				g_flag |= MASK_VERBOSE;
			else if (***av == 't')
				g_flag |= MASK_TOGO;
			else if (***av == 'n')
				g_flag |= MASK_NB_OP;
			else if (***av == 'i')
				g_flag |= MASK_INSERTION;
			else if (***av == 'b')
				g_flag |= MASK_BRUTE;
		}
		(**av)++;
	}
	return (OK);
}

void			ft_get_opt(int *ac, char ***av)
{
	g_flag = 0;
	(*av)++;
	if (*ac > 1 && ***av == '-')
	{
		(**av)++;
		if (***av >= '0' && ***av <= '9')
		{
			(**av)--;
			return ;
		}
		(*ac)--;
		if (ft_check_opt(av) == KO)
			ft_quit(KO);
		else if (ft_check_opt(av) == STOP)
			return ;
		(*av)++;
	}
	return ;
}
