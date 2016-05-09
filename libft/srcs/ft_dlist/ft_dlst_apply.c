/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:32:45 by jsaglio           #+#    #+#             */
/*   Updated: 2015/11/19 12:21:39 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void			ft_dlst_apply(t_dlist *head, void (*applyf)(t_dlist *))
{
	t_dlist	*it;
	t_dlist	*next;

	it = head->next;
	while (it != head)
	{
		next = it->next;
		applyf(it);
		it = next;
	}
	return ;
}
