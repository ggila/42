/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 21:24:59 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:32:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sub	ft_set_sub(t_dll *l)
{
	t_sub sub;

	ft_bzero(&sub, sizeof(t_sub));
	(sub.size) = 1;
	if (l)
	{
		sub.first = l;
		while (l->way != '|')
		{
			(sub.size)++;
			l = l->next;
		}
		sub.last = l;
	}
	return (sub);
}

static void		ft_rot_min(int min, int size, char l)
{
	while (l == A && g_l_a->n < min && size--)
		ft_op_add(RA);
	while (l == B && g_l_b->n < min && size--)
		ft_op_add(RB);
}

void			ft_merge_b_in_a(t_dll *end_a, t_dll *end_b)
{
	t_sub	sub_a;

	while (g_l_a != end_a || g_l_b != end_b)
	{
		sub_a = ft_set_sub(g_l_a);
		ft_rot_min(g_l_b->n, sub_a.size, A);
		while (g_l_b->n < g_l_a->n && g_l_b != end_b)
		{
			ft_op_add(PA);
			ft_op_add(RA);
		}
		if (g_l_a != end_a && g_l_a->n > g_l_b->n)
			ft_op_add(RA);
		if (g_l_a == end_a)
		{
			while (g_l_b != end_b)
			{
				ft_op_add(PA);
				ft_op_add(RA);
			}
		}
	}
}

static void		ft_merge_a_in_b(t_dll *end_a, t_dll *end_b)
{
	t_sub	sub_b;

	while (g_l_a != end_a || g_l_b != end_b)
	{
		sub_b = ft_set_sub(g_l_b);
		ft_rot_min(g_l_a->n, sub_b.size, B);
		while (g_l_a->n < g_l_b->n && g_l_a != end_a)
		{
			ft_op_add(PB);
			ft_op_add(RB);
		}
		if (g_l_b != end_b && g_l_b->n > g_l_a->n)
			ft_op_add(RB);
		if (g_l_b == end_b)
		{
			while (g_l_a != end_a)
			{
				ft_op_add(PB);
				ft_op_add(RB);
			}
		}
	}
}

void			ft_merge(void)
{
	t_sub	sub[2];
	t_dll	*end_a;
	t_dll	*end_b;

	while (g_size.l_b && g_size.l_b)
	{
		sub[LA] = ft_set_sub(g_l_a);
		sub[LB] = ft_set_sub(g_l_b);
		end_a = sub[LA].last->next;
		end_b = sub[LB].last->next;
		if (g_l_a == end_a && g_l_b == end_b)
			break ;
		ft_merge_b_in_a(end_a, end_b);
		ft_reorder_way(g_l_a);
		ft_reorder_way(g_l_b);
		sub[LA] = ft_set_sub(g_l_a);
		sub[LB] = ft_set_sub(g_l_b);
		end_a = sub[LA].last->next;
		end_b = sub[LB].last->next;
		ft_merge_a_in_b(end_a, end_b);
		ft_reorder_way(g_l_a);
		ft_reorder_way(g_l_b);
	}
	ft_finish();
}
