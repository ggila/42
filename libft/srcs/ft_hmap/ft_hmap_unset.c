/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 20:08:49 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/22 02:44:07 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"

void	ft_hmap_unset(char *key, void (*delf)(t_hm_base *), t_hmap *hm)
{
	t_hm_base		*old;

	if (!key || !delf || !hm)
		return ;
	if ((old = ft_hmap_get(key, hm)))
	{
		ft_dlst_del(&old->list);
		delf(old);
	}
	return ;
}
