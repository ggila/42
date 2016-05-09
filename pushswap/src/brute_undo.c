/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_undo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 11:48:15 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:57:30 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_go_back(t_op_dll **l, void (*ft_op_inv[11])(void))
{
	(*l)->op = -1;
	ft_op_inv[RRR]();
	(*l) = (*l)->prev;
}

static void	ft_inc_op(t_op_dll **l, void (*ft_op_inv[11])(void))
{
	if ((*l)->op_flag)
		ft_op_inv[(int)(*l)->op]();
	(*l)->op += 1;
	(*l)->op_flag = 1;
	if (((*l)->op == PA && g_size.l_b == 0) ||
	((*l)->op == PB && g_size.l_a == 0))
		(*l)->op_flag = 0;
	g_ft_op[(int)((*l)->op)]();
	(*l) = (*l)->next;
	while ((*l) != g_l_op)
	{
		(*l)->op = SA;
		(*l)->op_flag = 1;
		g_ft_op[SA]();
		(*l) = (*l)->next;
	}
}

static void	ft_reinit(t_op_dll **l)
{
	(*l) = (*l)->next;
	while ((*l) != g_l_op->next)
	{
		(*l)->op = SA;
		(*l)->op_flag = 1;
		g_ft_op[SA]();
		(*l) = (*l)->next;
	}
	g_l_op = g_l_op->next;
}

void		ft_brute_undo(t_op_dll *l_init, void (*ft_op_inv[11])(void))
{
	t_op_dll	*l;

	if (g_l_op->op == RRR)
	{
		l = g_l_op;
		while (l->op == RRR)
			ft_go_back(&l, ft_op_inv);
		if (l->next != l_init)
			ft_inc_op(&l, ft_op_inv);
		else
			ft_reinit(&l);
	}
	else if (g_l_op->op_flag)
		ft_op_inv[(int)(g_l_op->op)]();
	g_l_op->op = -1;
}
