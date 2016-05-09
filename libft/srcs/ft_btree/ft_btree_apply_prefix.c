/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:43:00 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/15 16:25:06 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_apply_prefix(t_btree *root, void (*applyf)(t_btree*))
{
	if (!root || !applyf)
		return ;
	applyf(root);
	ft_btree_apply_prefix(root->left, applyf);
	ft_btree_apply_prefix(root->right, applyf);
	return ;
}
