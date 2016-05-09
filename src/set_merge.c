/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 03:17:36 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:32:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_sub_way(t_sub sub[])
{
	int i;
	int diff;

	i = -1;
	diff = 0;
	while (sub[++i].way)
		diff += sub[i].way == '<' ? 1 : -1;
	return (diff);
}

static void	ft_egalise(t_sub sub[])
{
	char	way;
	int		diff;
	int		i;
	int		size;

	diff = ft_count_sub_way(sub);
	way = diff > 0 ? '<' : '>';
	diff = diff > 0 ? diff : -diff;
	i = -1;
	size = 1;
	while (diff > 1)
	{
		if (sub[++i].way && sub[i].way == way && sub[i].size == size)
		{
			sub[i].size = -sub[i].size;
			diff += -2;
		}
		else if (sub[i].way == 0)
		{
			i = -1;
			size++;
		}
	}
}

static void	ft_reverse_sub(char c, int size)
{
	if (size == 1)
		ft_op_add(c == '<' ? PB : RA);
	else if (size == 2)
	{
		ft_op_add(SA);
		ft_op_add(c == '<' ? PB : RA);
		ft_op_add(c == '<' ? PB : RA);
	}
	else if (c == '<')
	{
		ft_op_add(PB);
		ft_reverse_sub(c, size - 1);
		ft_op_add(PA);
		ft_op_add(RA);
	}
	while (c == '>' && size-- > 2)
	{
		ft_op_add(PB);
		ft_reverse_sub(c, size - 1);
		ft_op_add(PA);
		ft_op_add(RA);
	}
}

void		ft_reorder_way(t_dll *l)
{
	t_dll	*s;

	s = l;
	while (l->next != s)
	{
		if (l->n < l->next->n)
			l->way = '<';
		else
			l->way = '|';
		l = l->next;
	}
	l->way = '|';
}

void		ft_set_merge(t_sub *sub)
{
	int		i;

	i = 0;
	if (g_size.sub < 3)
		ft_insertion();
	if (g_size.sub > 2)
		ft_egalise(sub);
	while (sub[i].way)
	{
		if (sub[i].size < 0)
		{
			ft_reverse_sub(sub[i].way, -sub[i].size);
			sub[i].size = -sub[i].size;
		}
		else if (sub[i].way == '<')
			while (g_l_a != sub[i].last->next)
				ft_op_add(RA);
		else if (sub[i].way == '>')
			while (g_l_b != sub[i].last)
				ft_op_add(PB);
		i++;
	}
	ft_reorder_way(g_l_b);
	free(sub);
}
