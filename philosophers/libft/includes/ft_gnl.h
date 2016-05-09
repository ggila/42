/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 10:41:23 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/14 23:12:58 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include "ft_hlist.h"
# include "ft_macro.h"

# define GNL_BUFF_SIZE		512
# define C_MEM(ptr)			(CONTAINEROF(ptr, t_mem, lst))

/*
** Get_next_line
*/

typedef struct		s_mem
{
	t_hlist			lst;
	char			data[GNL_BUFF_SIZE + 1];
	int				fd_mem;
}					t_mem;

int					ft_gnl(int const fd, char **line);

#endif
