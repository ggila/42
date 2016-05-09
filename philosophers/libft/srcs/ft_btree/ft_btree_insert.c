/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:43:00 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/21 12:33:19 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_insert(t_btree **root, t_btree *node,
			int (*cmpf)(t_btree*, t_btree*))
{
	t_btree		*tmp;

	if (!root || !cmpf || !node)
		return ;
	if (!*root)
		return ((void)(*root = node));
	tmp = *root;
	if (cmpf(tmp, node) > 0)
		ft_btree_insert(&(tmp->left), node, cmpf);
	else
		ft_btree_insert(&(tmp->right), node, cmpf);
	return ;
}
