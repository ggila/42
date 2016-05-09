/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 20:08:49 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/22 01:42:37 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_str.h"

t_hm_base		*ft_hmap_get(char *key, t_hmap *hm)
{
	t_dlist		*head;
	t_dlist		*it;

	head = hm->head_array + (hm->hashf(key) % hm->size);
	it = head->next;
	while (it != head)
	{
		if (ft_strequ(key, C_HMAP_BASE(it)->key))
			return (C_HMAP_BASE(it));
		it = it->next;
	}
	return (0);
}
