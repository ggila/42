/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 20:08:49 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/14 14:06:03 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_mem.h"

t_hmap	*ft_hmap_new(int size, t_ui (*hashf)(char *))
{
	t_hmap		*hm;

	if (!(hm = FT_ZMALLOC(t_hmap, 1)))
		return (0);
	if (ft_hmap_init(size, hashf, hm) < 0)
	{
		free(hm);
		return (0);
	}
	return (hm);
}
