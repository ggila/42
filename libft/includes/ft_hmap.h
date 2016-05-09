/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <saglio.j@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 13:05:24 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HMAP_H
# define FT_HMAP_H

# include "ft_macro.h"
# include "ft_typedef.h"
# include "ft_dlist.h"
# include <stddef.h>

# define C_HMAP_BASE(ptr)	CONTAINEROF(ptr, t_hm_base, list)

typedef struct	s_hm_base
{
	t_dlist		list;
	char		*key;
}				t_hm_base;

typedef struct	s_hmap
{
	t_dlist		*head_array;
	size_t		size;
	t_ui		(*hashf)(char *);
}				t_hmap;

t_hmap			*ft_hmap_new(int size, t_ui (*hashf)(char *));
int				ft_hmap_init(int size, t_ui (*hashf)(char *), t_hmap *hm);
void			ft_hmap_delete(void (*del)(t_hm_base *), t_hmap *hm);

t_hm_base		*ft_hmap_get(char *key, t_hmap *hm);
void			ft_hmap_set(t_hm_base *new, void (*del)(t_hm_base *),
					t_hmap *hm);
void			ft_hmap_unset(char *key, void (*delf)(t_hm_base *), t_hmap *hm);

void			ft_puthmap(void (*print_list)(t_dlist *), t_hmap *hm);

#endif
