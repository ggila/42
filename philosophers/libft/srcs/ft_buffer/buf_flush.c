/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_flush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeansaglio <saglio.j@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 15:12:17 by jeansaglio        #+#    #+#             */
/*   Updated: 2015/09/05 13:06:04 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_put.h"

void			buf_flush(t_buffer *buf)
{
	if (!buf)
		return ;
	write(buf->fd, buf->ptr, buf->size);
	buf->size = 0;
	return ;
}
