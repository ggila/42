/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 10:30:41 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/23 11:23:36 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	debug_map(void)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++j < MAP_HEIGHT)
	{
		i = -1;
		while (++i < MAP_WIDTH)
			ft_putchar(g_map[j][i]);
		ft_putchar('\n');
	}
}

void	print_float(double f)
{
	if (f < 0)
	{
		ft_putchar('-');
		f *= -1;
	}
	ft_putnbr(f);
	f -= (int)f;
	ft_putchar('.');
	f *= 100;
	if (f < 10)
		ft_putnbr(0);
	ft_putnbr(f);
}

void	debug_pt(t_pt pt)
{
	ft_putchar('(');
	print_float(pt.x);
	ft_putchar('|');
	print_float(pt.y);
	ft_putchar(')');
}
