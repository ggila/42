/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 12:58:42 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 01:54:48 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

static void		s_list_del(t_dlist *prev, t_dlist *next)
{
	next->prev = prev;
	prev->next = next;
}

void			ft_dlst_del(t_dlist *entry)
{
	s_list_del(entry->prev, entry->next);
}
