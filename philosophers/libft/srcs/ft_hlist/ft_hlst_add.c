/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 19:49:16 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 13:17:37 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

static void		s_hlst_add(t_hlist *new, t_hlist *prev, t_hlist *next)
{
	prev->next = new;
	new->next = next;
}

void			ft_hlst_add(t_hlist *new, t_hlist *head)
{
	s_hlst_add(new, head, head->next);
}
