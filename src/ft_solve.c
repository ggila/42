/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 04:18:23 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

double		ft_sqrt(double d)
{
	int		i;
	double	z;

	i = 10;
	z = d / 2;
	while (i--)
		z = z - (z * z - d) / (2 * z);
	return (z);
}

static void	ft_solve_easy(void)
{
	if (g_monom[1] == 0)
	{
		if (g_monom[0] != 0)
			ft_quit("false equation, no solution", NULL, 0, -1);
		ft_quit("trivial equation, each number is solution", NULL, 0, -1);
	}
	else
	{
		ft_putstr("equation has only one solution:\n");
		ft_putchar(g_x);
		ft_putstr(" = ");
		ft_put_double(-C / B);
		ft_putchar('\n');
	}
	ft_putstr("-------------------------------------------------\n");
}

static void	ft_solve_second_degree(void)
{
	double	delta;

	delta = B * B - 4 * A * C;
	ft_put_delta(delta);
	ft_put_sol(delta);
	ft_putstr("\n-------------------------------------------------\n");
}

void		ft_solve(void)
{
	ft_put_all_monom();
	if (g_monom[3] == 0 && g_monom[2] == 0)
		ft_solve_easy();
	else if (g_monom[3] == 0 && g_monom[2])
		ft_solve_second_degree();
	else if (g_monom[3])
		ft_solve_three();
}
