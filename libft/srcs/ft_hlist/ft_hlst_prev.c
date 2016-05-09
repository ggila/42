/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlst_prev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 19:49:16 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 13:17:31 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

t_hlist			*ft_hlst_prev(t_hlist *entry, t_hlist *head)
{
	t_hlist		*iterator;

	iterator = head;
	while (iterator->next != head)
	{
		if (iterator->next == entry)
			return (iterator);
		iterator = iterator->next;
	}
	return ((iterator->next == entry) ? iterator : 0);
}
