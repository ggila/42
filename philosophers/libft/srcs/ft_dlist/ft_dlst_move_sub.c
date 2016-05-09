/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_move_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 13:02:47 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 12:33:03 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

static void	s_remove_from_original_list(t_dlist *first, t_dlist *last)
{
	first->prev->next = last->next;
	last->next->prev = first->prev;
	return ;
}

void		ft_dlst_move_sub(t_dlist *first, t_dlist *last, t_dlist *head)
{
	t_dlist		*after;

	after = head->next;
	s_remove_from_original_list(first, last);
	head->next = first;
	first->prev = head;
	last->next = after;
	after->prev = last;
	return ;
}
