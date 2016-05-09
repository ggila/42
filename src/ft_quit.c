/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 02:54:04 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void	ft_print_error(int n)
{
	ft_putstr("\n");
	ft_putendl(g_str_init);
	while (n--)
		ft_putchar(' ');
	ft_putstr("^");
}

void		ft_quit(char *str, char *str2, char c, int n)
{
	if (!(g_flag & MASK_DEBUG))
	{
		ft_putstr(str);
		if (c)
		{
			ft_putchar('\'');
			ft_putchar(c);
			ft_putchar('\'');
		}
		if (n >= 0)
			ft_print_error(n);
		if (str2)
			ft_putstr(str2);
		ft_putstr("\n");
	}
	exit(OK);
}
