/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 20:08:49 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 22:40:53 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_mem.h"

int				ft_hmap_init(int size, t_ui (*hashf)(char *), t_hmap *hm)
{
	int		i;

	if (!(hm->head_array = FT_ZMALLOC(t_dlist, size)))
		return (-1);
	hm->size = size;
	hm->hashf = hashf;
	i = 0;
	while (i < size)
	{
		DLIST_HEAD_INIT(hm->head_array[i]);
		i++;
	}
	return (0);
}
