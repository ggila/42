/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlst_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 19:49:16 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/14 14:05:39 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

void	ft_hlst_replace(t_hlist *old, t_hlist *new, t_hlist *head)
{
	t_hlist		*prev;

	prev = ft_hlst_prev(old, head);
	prev->next = new;
	new->next = old->next;
}
