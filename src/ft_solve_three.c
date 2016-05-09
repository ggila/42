/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 06:50:20 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void	ft_solve_three_down(void)
{
	int i;

	i = -1;
	while (++i != 3)
		g_monom[i] = g_monom[i + 1];
	g_monom[3] = 0;
	ft_solve();
}

void		ft_solve_three(void)
{
	if (g_monom[0] == 0)
		ft_solve_three_down();
}
