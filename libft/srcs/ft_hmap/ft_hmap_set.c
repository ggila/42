/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 20:08:49 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 13:05:14 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"

void			ft_hmap_set(t_hm_base *new, void (*delf)(t_hm_base *),
					t_hmap *hm)
{
	unsigned int	id;

	if (!new || !hm)
		return ;
	ft_hmap_unset(new->key, delf, hm);
	id = hm->hashf(new->key) % hm->size;
	ft_dlst_add(&new->list, hm->head_array + id);
	return ;
}
