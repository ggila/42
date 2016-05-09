/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_del_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 12:59:40 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 01:54:52 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

static void		s_list_del(t_dlist *prev, t_dlist *next)
{
	next->prev = prev;
	prev->next = next;
}

void			ft_dlst_del_init(t_dlist *entry)
{
	s_list_del(entry->prev, entry->next);
	ft_dlst_init_head(entry);
}
