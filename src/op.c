/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 20:39:30 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:32:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char l)
{
	int tempn;
	int tempt;

	if (!(l % A) && g_l_a && (g_l_a->next != g_l_a))
	{
		tempn = g_l_a->n;
		g_l_a->n = g_l_a->next->n;
		g_l_a->next->n = tempn;
		tempt = g_l_a->togo;
		g_l_a->togo = g_l_a->next->togo;
		g_l_a->next->togo = tempt;
	}
	if (!(l % B) && g_l_b && (g_l_b->next != g_l_b))
	{
		tempn = g_l_b->n;
		g_l_b->n = g_l_b->next->n;
		g_l_b->next->n = tempn;
		tempt = g_l_b->togo;
		g_l_b->togo = g_l_b->next->togo;
		g_l_b->next->togo = tempt;
	}
}

void	ft_push(char l)
{
	if (!(l % A) && g_l_b)
	{
		ft_push_gen(&g_l_b, &g_l_a);
		g_size.l_a += 1;
		g_size.l_b += -1;
	}
	if (!(l % B) && g_l_a)
	{
		ft_push_gen(&g_l_a, &g_l_b);
		g_size.l_b += 1;
		g_size.l_a += -1;
	}
}

void	ft_rotate_right(char l)
{
	if (!(l % A) && g_l_a)
		g_l_a = g_l_a->prev;
	if (!(l % B) && g_l_b)
		g_l_b = g_l_b->prev;
}

void	ft_rotate_left(char l)
{
	if (!(l % A) && g_l_a)
		g_l_a = g_l_a->next;
	if (!(l % B) && g_l_b)
		g_l_b = g_l_b->next;
}
