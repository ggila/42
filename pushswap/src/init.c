/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 20:33:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:57:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_scan_sub(t_dll *end, t_dll **l, t_sub *sub, char way)
{
	while ((*l)->next != end && (*l)->way == (*l)->next->way)
	{
		(sub[g_size.sub].size)++;
		(*l)->way = way;
		(*l) = (*l)->next;
	}
	if ((*l)->next != end)
	{
		(*l) = (*l)->next;
		(*l)->way = '|';
		(sub[g_size.sub].size)++;
	}
}

void		ft_set_sub(t_sub *sub, t_dll *l_a)
{
	t_dll	*end;
	char	way;

	end = l_a;
	while (l_a != end || g_size.sub == 0)
	{
		sub[g_size.sub].first = l_a;
		sub[g_size.sub].size = 1;
		way = l_a->n - l_a->next->n < 0 ||
		l_a->togo == g_size.total ? '<' : '>';
		sub[g_size.sub].way = way;
		ft_scan_sub(end, &l_a, sub, way);
		sub[g_size.sub].last = l_a;
		(g_size.sub)++;
		if (l_a->next != end)
			l_a = l_a->next;
		else
		{
			l_a->way = '|';
			break ;
		}
	}
}

void		ft_la_set(void)
{
	int		i;
	t_dll	*s;

	s = g_l_a;
	i = 0;
	while (s->way != '<')
	{
		s = s->next;
		i++;
		if (i > g_size.l_a)
			break ;
	}
	s = g_l_a;
	while (s->way != '<')
	{
		s = s->prev;
		i--;
		if (i > g_size.l_a)
			break ;
	}
	while (g_l_a->way != '<')
		ft_op_add(i < 0 ? RA : RRA);
}

t_dll		*ft_dll_set(int ac, char **av)
{
	t_dll	*dll;
	t_dll	*last;
	int		tab[ac - 1];
	int		i;

	i = -1;
	dll = NULL;
	while (++i < ac - 1)
	{
		if (ft_strcmp(ft_itoa(ft_atoi(av[i])), av[i]) || ft_strchr(av[i], '.'))
			ft_quit(KO);
		tab[i] = ft_atoi(av[i]);
	}
	ft_mergesort_array((void*)tab, f_cmp, sizeof(int), ac - 2);
	while (--i)
		if (tab[i] == tab[i - 1])
			ft_quit(KO);
	while (--ac)
		dll = ft_dll_add(dll, av[ac - 1], &last, tab);
	dll->prev = last;
	last->next = dll;
	dll->prev->way = dll->togo > dll->prev->togo ? '<' : '>';
	if (dll->togo == g_size.total)
		dll->way = '<';
	return (dll);
}

void		ft_init_all(int ac, char **av, t_sub **sub)
{
	g_size.l_a = ac - 1;
	g_size.l_b = 0;
	g_size.total = ac - 1;
	g_size.sub = 0;
	ft_op_init();
	g_l_a = ft_dll_set(ac, av);
	if (!(*sub = (t_sub*)malloc(sizeof(t_sub) * (ac - 1))))
		exit(KO);
	ft_bzero(*sub, (ac - 1) * sizeof(t_sub));
	ft_set_sub(*sub, g_l_a);
	g_l_b = NULL;
	g_l_op = NULL;
	if (g_flag & MASK_VERBOSE)
		ft_putddll();
	if (ft_sort(g_l_a) == OK)
		exit(OK);
}
