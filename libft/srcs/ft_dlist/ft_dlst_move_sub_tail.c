/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_move_sub_tail.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 13:02:47 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 12:32:54 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

static void	s_remove_from_original_list(t_dlist *first, t_dlist *last)
{
	first->prev->next = last->next;
	last->next->prev = first->prev;
	return ;
}

void		ft_dlst_move_sub_tail(t_dlist *first, t_dlist *last, t_dlist *head)
{
	t_dlist		*before;

	before = head->prev;
	s_remove_from_original_list(first, last);
	before->next = first;
	first->prev = before;
	last->next = head;
	head->prev = last;
	return ;
}
