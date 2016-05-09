/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 00:44:24 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:32:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_sort(t_dll *l_a)
{
	t_dll	*end;

	if (g_size.l_b || !g_size.l_a)
		return (KO);
	end = l_a;
	while (l_a->next != end)
	{
		if (l_a->n >= l_a->next->n)
			return (KO);
		l_a = l_a->next;
	}
	return (OK);
}

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	if (!size)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = '\0';
	return ((void*)str);
}

void	ft_insertion(void)
{
	int i;

	i = 1;
	while (1)
	{
		if (g_l_a->togo > g_l_a->next->togo && (i % g_size.total))
			ft_op_add(SA);
		else if (i++)
			ft_op_add(RA);
	}
}

void	ft_print_flag(void)
{
	ft_putendl("--------------------------------");
	ft_putstr("g_flag\nMASK_VERBOSE : ");
	ft_putnbr(!!(g_flag & MASK_VERBOSE));
	ft_putstr("\nMASK_TOGO : ");
	ft_putnbr(!!(g_flag & MASK_TOGO));
	ft_putstr("\nMASK_BRUTE : ");
	ft_putnbr(!!(g_flag & MASK_BRUTE));
	ft_putstr("\nMASK_INSERTION : ");
	ft_putnbr(!!(g_flag & MASK_INSERTION));
	ft_putstr("\nMASK_NB_OP : ");
	ft_putnbr(!!(g_flag & MASK_NB_OP));
	ft_putendl("\n--------------------------------");
}

int		ft_check_way(int togo)
{
	t_dll	*l;
	int		i;

	i = 0;
	l = g_l_a;
	while (l->togo != togo)
	{
		i++;
		l = l->next;
	}
	l = g_l_a;
	while (l->togo != togo)
	{
		i--;
		l = l->prev;
	}
	return (i);
}
