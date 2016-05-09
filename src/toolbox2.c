/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 19:22:09 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:32:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_decrease(void)
{
	t_dll	*l;
	int		flag;

	flag = 0;
	if (g_l_a->togo < g_l_a->next->togo)
		flag++;
	l = g_l_a->next;
	while (l != g_l_a)
	{
		if (l->togo < l->next->togo)
			flag++;
		l = l->next;
	}
	return (flag == 1 ? OK : KO);
}

void	ft_ordered_list(char c)
{
	int i;

	if (c == '<')
	{
		i = ft_check_way(1);
		while (1)
			ft_op_add(i > 0 ? RRA : RA);
	}
	else if (c == '>')
	{
		i = (g_l_a->togo == g_size.total) ? 0 : ft_check_way(g_size.total);
		while (g_l_a->togo != g_size.total)
			ft_op_add(i > 0 ? RRA : RA);
		if (g_size.l_a == 2)
			ft_op_add(SA);
		while (g_size.l_a != 3)
			ft_op_add(PB);
		ft_op_add(SA);
		ft_op_add(RRA);
		while (1)
		{
			ft_op_add(PA);
			ft_op_add(RA);
		}
	}
}

void	ft_finish(void)
{
	while (1)
	{
		if (g_size.l_b && ((g_l_b->n < g_l_a->n)
		|| ((g_l_b->togo == g_l_a->prev->togo + 1) && (g_l_a->togo == 1))))
			ft_op_add(PA);
		ft_op_add(RA);
	}
}

char	ft_l_sorted(t_dll *l, char c)
{
	t_dll	*end;

	if ((c == A && g_size.l_a > 1) || (c == B && g_size.l_b > 1))
	{
		end = l;
		while (l->next != end)
		{
			if (c == B && l->togo <= l->next->togo)
				return (KO);
			if (c == A && l->togo >= l->next->togo)
				return (KO);
			l = l->next;
		}
	}
	return (OK);
}

int		f_cmp(const void *x, const void *y)
{
	int	a;
	int	b;

	a = *((int*)x);
	b = *((int*)y);
	if (a > b)
		return (1);
	else
		return (-1);
}
