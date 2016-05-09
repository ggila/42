/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 20:38:47 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:27:20 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_gen(t_dll **l1, t_dll **l2)
{
	t_dll	*temp;
	char	flag;

	if (*l1)
	{
		temp = *l1;
		(*l1)->prev->next = (*l1)->next;
		(*l1)->next->prev = (*l1)->prev;
		*l1 = (*l1) != (*l1)->next ? (*l1)->next : NULL;
		if (!*l2)
		{
			*l2 = temp;
			(*l2)->next = *l2;
			(*l2)->prev = *l2;
		}
		else
		{
			flag = (*l2 != (*l2)->next);
			temp->prev = flag ? (*l2)->prev : *l2;
			temp->next = *l2;
			(*l2)->prev->next = temp;
			(*l2)->prev = temp;
			*l2 = temp;
		}
	}
}

void	ft_op_add(char op)
{
	t_op_dll	*new;

	if (!(new = (t_op_dll*)malloc(sizeof(t_op_dll))))
		exit(KO);
	new->op = op;
	if (g_l_op == NULL)
	{
		g_l_op = new;
		g_l_op->prev = g_l_op;
		g_l_op->next = g_l_op;
		g_size.l_op = 1;
	}
	else
	{
		new->prev = (g_l_op != g_l_op->next) ? g_l_op->prev : g_l_op;
		new->next = g_l_op;
		g_l_op->prev = new;
		g_l_op->prev->next = new;
		g_size.l_op++;
	}
	ft_putop(op);
	if (ft_sort(g_l_a) == OK)
		exit(ft_quit(OK));
}

t_dll	*ft_dll_add(t_dll *dll, char *av, t_dll **last, int *tab)
{
	t_dll	*new;
	int		i;

	if (!(new = (t_dll*)malloc(sizeof(t_dll))))
		exit(KO);
	new->n = ft_atoi(av);
	i = 0;
	while (ft_atoi(av) != tab[i])
		i++;
	new->togo = i + 1;
	if (!dll)
		return (*last = new);
	dll->prev = new;
	new->next = dll;
	new->sub = NULL;
	new->way = new->togo > new->next->togo ? '>' : '<';
	if (new->togo == g_size.total)
		new->way = '<';
	return (new);
}
