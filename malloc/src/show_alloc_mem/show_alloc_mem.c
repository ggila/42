/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 16:51:53 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/02 17:48:01 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_glob	g_all;

void			show_alloc_mem(void)
{
	void	(*printfunc)(t_reg*);

	printfunc = ft_env("DEBUG_MALLOC") ? show_region_deb : show_region;
	ft_putstr("TINY : ");
	g_all.tiny ? printfunc(g_all.tiny) : ft_putstr("none\n");
	ft_putstr("\n------------------------------------\n");
	ft_putstr("SMALL : ");
	g_all.small ? printfunc(g_all.small) : ft_putstr("none\n");
	ft_putstr("\n------------------------------------\n");
	ft_putstr("LARGE : ");
	g_all.large ? printfunc(g_all.large) : ft_putstr("none\n");
	ft_putstr("\n");
}
