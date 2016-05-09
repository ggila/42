/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 20:39:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:26:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_quit(char c)
{
	if (c == OK)
		ft_putchar('\n');
	else
		ft_putendl_fd("Error", 1);
	if (g_flag & MASK_NB_OP)
	{
		ft_putstr("\ntotal op : ");
		ft_putnbr(g_size.l_op);
		ft_putchar('\n');
	}
	exit(OK);
}

int		main(int ac, char **av)
{
	t_sub *sub;

	if (ac == 1)
		return (OK);
	ft_get_opt(&ac, &av);
	if (ac == 1)
		return (OK);
	ft_init_all(ac, av, &sub);
	if (!(g_flag & MASK_INSERTION))
		ft_bruteforce();
	if (g_flag & MASK_INSERTION || g_size.total == 7)
		ft_insertion();
	else
	{
		ft_set_merge(sub);
		ft_merge();
	}
	return (OK);
}
