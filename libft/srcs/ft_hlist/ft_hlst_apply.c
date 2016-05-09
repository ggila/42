/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlst_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:32:45 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/15 11:57:29 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

void			ft_hlst_apply(t_hlist *head, void (*applyf)(t_hlist *))
{
	t_hlist	*it;
	t_hlist	*next;

	it = head->next;
	while (it != head)
	{
		next = it->next;
		applyf(it);
		it = next;
	}
	return ;
}
