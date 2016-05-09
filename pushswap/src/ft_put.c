/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 20:39:12 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:49:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putddll(void)
{
	ft_putchar('\n');
	ft_putstr("l_a (");
	ft_putnbr(g_size.l_a);
	ft_putstr(") : ");
	ft_putdll(g_l_a);
	ft_putchar('\n');
	ft_putstr("l_b (");
	ft_putnbr(g_size.l_b);
	ft_putstr(") : ");
	ft_putdll(g_l_b);
	if (g_flag & MASK_VERBOSE)
		ft_putendl("");
}

void	ft_putsub(t_sub *sub)
{
	int		i;
	t_dll	*l;

	i = -1;
	ft_putendl("\nSublist :");
	while (sub[++i].way)
	{
		ft_putchar(sub[i].way);
		ft_putstr("   ");
		ft_putnbr(sub[i].size);
		ft_putstr("\t\t");
		l = sub[i].first;
		while (l->prev != sub[i].last)
		{
			ft_putnbr(l->n);
			ft_putchar(l->way);
			l = l->next;
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

void	ft_putdll(t_dll *dll)
{
	t_dll *end;

	end = dll;
	if (dll)
	{
		while (dll->next != end)
		{
			ft_putnbr(g_flag & MASK_TOGO ? dll->togo : dll->n);
			ft_putstr("  ");
			dll = dll->next;
		}
		ft_putnbr(g_flag & MASK_TOGO ? dll->togo : dll->n);
		dll = dll->next;
	}
	if (g_flag & MASK_VERBOSE)
		ft_putendl("");
}

void	ft_print_opdll(t_op_dll *l_op)
{
	t_op_dll	*l;

	while (l_op->pos != 1)
		l_op = l_op->next;
	if (l_op->op >= 0 && l_op->op <= 10)
		ft_putstr(g_op[(int)(l_op->op)]);
	ft_putchar(' ');
	l = l_op->next;
	while (l != l_op)
	{
		if (l->op >= 0 && l->op <= 10)
			ft_putstr(g_op[(int)(l->op)]);
		ft_putchar(' ');
		l = l->next;
	}
}

void	ft_putop(char n)
{
	g_ft_op[(int)n]();
	if (g_flag & MASK_VERBOSE)
		ft_putendl("");
	if (g_flag & MASK_VERBOSE)
		ft_putstr("^^^---->");
	ft_putstr(g_op[(int)n]);
	if (g_flag & MASK_VERBOSE)
		ft_putendl(">----vvv");
	if (g_flag & MASK_VERBOSE)
	{
		ft_putchar('\n');
		ft_putddll();
	}
	else
		ft_putchar(' ');
}
