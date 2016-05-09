/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 10:47:07 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/16 16:56:32 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist		*ft_dlst_find(t_dlist *head, int (*boolf)(t_dlist*), int dir)
{
	t_dlist	*it;

	it = (dir < 0) ? head->prev : head->next;
	while (it != head)
	{
		if (boolf(it))
			return (it);
		it = (dir < 0) ? it->prev : it->next;
	}
	return (0);
}
