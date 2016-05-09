/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_add_tail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 12:57:54 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 01:54:43 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

static void		s_ft_dlst_add(t_dlist *new, t_dlist *prev, t_dlist *next)
{
	prev->next = new;
	new->next = next;
	new->prev = prev;
	next->prev = new;
}

void			ft_dlst_add_tail(t_dlist *new, t_dlist *head)
{
	s_ft_dlst_add(new, head->prev, head);
}
