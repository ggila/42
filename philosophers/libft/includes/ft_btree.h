/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:31:30 by jsaglio           #+#    #+#             */
/*   Updated: 2015/12/01 18:03:45 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# define BTREE_ROOT				((t_btree){0})
# define BTREE_ROOT_INIT(name)	name = BTREE_ROOT

typedef struct	s_btree
{
	struct s_btree		*left;
	struct s_btree		*right;
}				t_btree;

void			ft_btree_insert(t_btree **root, t_btree *node,
					int (*cmpf)(t_btree*, t_btree*));
void			ft_btree_apply_prefix(t_btree *root, void (*applyf)(t_btree*));
void			ft_btree_apply_infix(t_btree *root, void (*applyf)(t_btree*));
void			ft_btree_apply_suffix(t_btree *root, void (*applyf)(t_btree*));

#endif
