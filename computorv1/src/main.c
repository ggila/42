/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 01:57:46 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		main(int ac, char **av)
{
	char *str;

	if (ac == 3)
		ft_get_opt(&ac, &av);
	if (ac != 2)
		ft_quit(USAGE, NULL, 0, 0);
	if (g_flag & MASK_FLAG)
		ft_print_flag(1);
	ft_bzero(g_monom, 4 * sizeof(double));
	g_flag_op = 0;
	str = g_flag ? av[2] : av[1];
	while (ft_isspace(*str))
		str++;
	ft_check_input(str);
	if (g_flag & MASK_DEBUG)
		ft_putendl("CHECK_INPUT OK");
	ft_get_values(str);
	if (g_flag & MASK_DEBUG)
		ft_putendl("GET_COEF OK");
	ft_solve();
	if (g_flag & MASK_VISUAL)
		ft_mlx(str);
	return (OK);
}
