/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:25:18 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/20 01:02:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 32

typedef struct	s_gnl
{
	int			fd;
	char		*str;
}				t_gnl;

int				get_next_line(int const fd, char **line);

#endif
