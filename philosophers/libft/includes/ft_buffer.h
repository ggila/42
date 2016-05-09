/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeansaglio <saglio.j@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 15:12:17 by jeansaglio        #+#    #+#             */
/*   Updated: 2015/09/07 10:55:13 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include <stddef.h>

# define T_BUFFER_SIZE		4096
# define BUF_NEW(fd)		((t_buffer){fd, {0}, 0, T_BUFFER_SIZE})

typedef struct	s_buffer
{
	char		ptr[T_BUFFER_SIZE];
	size_t		size;
	int			fd;
}				t_buffer;

void			buf_write(t_buffer *dst, char *src, size_t n);
void			buf_flush(t_buffer *buf);

void			buf_putstr(t_buffer *dst, char *str);
void			buf_putendl(t_buffer *dst, char *str);

#endif
