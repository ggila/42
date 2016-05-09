/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 20:08:49 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/22 02:37:27 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_putf.h"

void			ft_puthmap(void (*print_list)(t_dlist *), t_hmap *hm)
{
	size_t		i;

	i = 0;
	while (i < hm->size)
	{
		ft_putf("%u:\n", i);
		print_list(hm->head_array + i);
		i++;
	}
	return ;
}
