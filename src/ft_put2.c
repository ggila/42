/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 05:35:44 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_put_sol2(double delta, double d)
{
	ft_putstr("    |    ");
	ft_putchar(g_x);
	ft_putstr(" = ");
	if (delta >= 0)
		ft_put_double((-B + d) / (2 * A));
	else
	{
		ft_put_double(-B / (2 * A));
		ft_putstr(" + i * ");
		ft_put_double(d / (2 * A));
	}
}

void	ft_put_sol(double delta)
{
	double	d;

	ft_putchar('\n');
	d = ft_sqrt(ABS(delta));
	ft_putchar(g_x);
	ft_putstr(" = ");
	if (delta == 0)
		ft_putnbr(-B / (2 * A));
	else if (delta > 0)
		ft_put_double((-B - d) / (2 * A));
	else
	{
		ft_put_double(-B / (2 * A));
		ft_putstr(" + i * ");
		ft_put_double(-d / (2 * A));
	}
	if (delta)
		ft_put_sol2(delta, d);
}

void	ft_put_delta(double delta)
{
	ft_putendl("equation form:\tax^2 + bx + c = 0");
	ft_putendl("(delta: b^2 - 4ac)");
	ft_putendl("");
	ft_putstr("delta = ");
	ft_put_double(delta);
	ft_putendl("\n");
	if (delta > 0)
		ft_putendl("delta > 0: equation has two real solution\n"
		"x = (-b +/- sqrt(delta)) / 2a");
	if (delta < 0)
		ft_putendl("delta < 0: equation has two complex solution\n"
		"x = (-b +/- i * sqrt(delta)) / 2a");
	if (delta == 0)
		ft_putendl("delta = 0: equation has one real solution\nx = -b / 2a");
}
