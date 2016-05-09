/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 10:18:41 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

t_pll		*ft_pll_new(void)
{
	t_pll *new;

	if (!(new = (t_pll*)malloc(sizeof(t_pll))))
		ft_error("malloc failed (ft_pll_new)");
	new->n = NULL;
	return (new);
}

t_pll		*ft_pll_add(t_pll *fd)
{
	t_pll *new;

	new = ft_pll_new();
	new->n = fd;
	return (new);
}
