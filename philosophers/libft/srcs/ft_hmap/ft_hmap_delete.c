/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 20:08:49 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/23 17:21:49 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"

void		ft_hmap_delete(void (*del_node)(t_hm_base *), t_hmap *hm)
{
	unsigned int	i;
	t_hm_base		*base;

	i = 0;
	while (i < hm->size)
	{
		while (!ft_dlst_empty(hm->head_array + i))
		{
			base = C_HMAP_BASE(hm->head_array[i].next);
			ft_dlst_del(&base->list);
			del_node(base);
		}
		i++;
	}
	return ;
}
