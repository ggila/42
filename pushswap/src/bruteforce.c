/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:08:57 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:50:26 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_brute_nb_op(void)
{
	int		i;
	int		end;
	int		total;
	int		op_lvl;

	i = 0;
	total = 0;
	op_lvl = 1;
	end = g_size.total == 5 ? 8 : NB_BRUTE;
	end = g_size.total == 6 ? 7 : end;
	if (g_size.total > 20)
		end = 5;
	while (++i <= end)
	{
		op_lvl *= NB_OP;
		total += op_lvl;
	}
	return (total);
}

static void	ft_init_opdll(void (*ft_op_inv[11])(void))
{
	t_op_dll	*new;
	t_op_dll	*last;
	int			i;

	if (!(last = (t_op_dll*)malloc(sizeof(t_op_dll))))
		exit(ft_quit(KO));
	last->op = -1;
	last->pos = NB_BRUTE;
	g_l_op = last;
	i = 1;
	while (++i <= NB_BRUTE)
	{
		if (!(new = (t_op_dll*)malloc(sizeof(t_op_dll))))
			exit(ft_quit(KO));
		new->op = -1;
		new->next = g_l_op;
		new->pos = NB_BRUTE + 1 - i;
		g_l_op->prev = new;
		g_l_op = new;
	}
	g_l_op->prev = last;
	last->next = g_l_op;
	ft_init_op_inv(ft_op_inv);
}

static void	ft_brute_add(char op)
{
	g_l_op->op = op;
	g_l_op->op_flag = 1;
	if ((op == PA && g_size.l_b == 0) || (op == PB && g_size.l_a == 0))
		g_l_op->op_flag = 0;
	g_ft_op[(int)op]();
	return ;
}

void		ft_bruteforce(void)
{
	int			i;
	int			nb_brute_op;
	void		(*ft_op_inv[11])(void);
	t_op_dll	*l_init;

	ft_init_opdll(ft_op_inv);
	l_init = g_l_op;
	nb_brute_op = ft_brute_nb_op();
	i = 0;
	while (++i <= nb_brute_op)
	{
		ft_brute_add((i - 1) % NB_OP);
		if (ft_sort(g_l_a) == OK)
		{
			ft_print_opdll(g_l_op);
			ft_quit(OK);
		}
		ft_brute_undo(l_init, ft_op_inv);
	}
}
