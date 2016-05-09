/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:43:00 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/15 16:25:02 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(t_btree*))
{
	if (!root || !applyf)
		return ;
	ft_btree_apply_infix(root->left, applyf);
	applyf(root);
	ft_btree_apply_infix(root->right, applyf);
	return ;
}
