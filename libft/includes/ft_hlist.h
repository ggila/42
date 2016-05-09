/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 14:50:08 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/15 11:59:55 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HLIST_H
# define FT_HLIST_H

# define HLIST_HEAD(name)		(t_hlist){&(name)}
# define HLIST_HEAD_NULL		(t_hlist){0}
# define HLIST_HEAD_INIT(name)	name = HLIST_HEAD(name)

typedef struct	s_hlist
{
	struct s_hlist	*next;
}				t_hlist;

/*
** Hlist functions
*/

void			ft_hlst_init_head(t_hlist *list);
t_hlist			*ft_hlst_prev(t_hlist *entry, t_hlist *head);
void			ft_hlst_add(t_hlist *new, t_hlist *head);
void			ft_hlst_add_tail(t_hlist *new, t_hlist *head);
void			ft_hlst_del(t_hlist *entry, t_hlist *head);
void			ft_hlst_del_init(t_hlist *entry, t_hlist *head);
void			ft_hlst_replace(t_hlist *old, t_hlist *new, t_hlist *head);
void			ft_hlst_replace_init(t_hlist *old, t_hlist *new, t_hlist *head);
void			ft_hlst_move(t_hlist *list, t_hlist *head_src,
					t_hlist *head_dst);
void			ft_hlst_move_tail(t_hlist *list, t_hlist *head_src,
					t_hlist *head_dst);
int				ft_hlst_is_last(t_hlist *list, t_hlist *head);
int				ft_hlst_empty(t_hlist *head);
int				ft_hlst_is_singular(t_hlist *head);
void			ft_hlst_apply(t_hlist *head, void (*apply)(t_hlist *));
int				ft_hlst_len(t_hlist *head);

#endif
