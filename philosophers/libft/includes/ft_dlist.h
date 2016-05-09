/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 16:58:20 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/12 20:11:05 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# define DLIST_HEAD(name)		(t_dlist){&(name), &(name)}
# define DLIST_HEAD_NULL		(t_dlist){0, 0}
# define DLIST_HEAD_INIT(name)	name = DLIST_HEAD(name)

typedef struct	s_dlist
{
	struct s_dlist	*prev;
	struct s_dlist	*next;
}				t_dlist;

/*
** Dlist functions
*/

void			ft_dlst_init_head(t_dlist *list);
t_dlist			*ft_dlst_next(t_dlist *list, t_dlist *head);
t_dlist			*ft_dlst_prev(t_dlist *list, t_dlist *head);
void			ft_dlst_add(t_dlist *new, t_dlist *head);
void			ft_dlst_add_tail(t_dlist *new, t_dlist *head);
void			ft_dlst_del(t_dlist *entry);
void			ft_dlst_del_init(t_dlist *entry);
void			ft_dlst_replace(t_dlist *old, t_dlist *new);
void			ft_dlst_replace_init(t_dlist *old, t_dlist *new);
void			ft_dlst_move(t_dlist *list, t_dlist *head);
void			ft_dlst_move_tail(t_dlist *list, t_dlist *head);
void			ft_dlst_move_sub(t_dlist *first, t_dlist *last, t_dlist *head);
void			ft_dlst_move_sub_tail(t_dlist *first, t_dlist *last,
					t_dlist *head);
int				ft_dlst_is_last(t_dlist *list, t_dlist *head);
int				ft_dlst_empty(t_dlist *head);
int				ft_dlst_is_singular(t_dlist *head);
int				ft_dlst_len(t_dlist *head);
t_dlist			*ft_dlst_find(t_dlist *head, int (*boolf)(t_dlist*), int dir);
void			ft_dlst_apply(t_dlist *head, void (*applyf)(t_dlist *));
void			ft_putdlst(t_dlist *head, void (*print)(t_dlist *),
					char *sep);
void			ft_putdlst_fd(int fd, t_dlist *head
					, void (*print)(t_dlist *, int), char *sep);

#endif
