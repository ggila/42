/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlst_del_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 19:49:16 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 13:17:35 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

static void		s_hlst_del(t_hlist *prev, t_hlist *next)
{
	prev->next = next;
}

void			ft_hlst_del_init(t_hlist *entry, t_hlist *head)
{
	t_hlist		*prev;

	prev = ft_hlst_prev(entry, head);
	s_hlst_del(prev, entry->next);
	ft_hlst_init_head(entry);
}
