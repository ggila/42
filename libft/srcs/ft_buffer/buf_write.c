/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeansaglio <saglio.j@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 15:12:17 by jeansaglio        #+#    #+#             */
/*   Updated: 2015/08/16 19:38:37 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"

void			buf_write(t_buffer *dst, char *src, size_t n)
{
	if (!dst || !src || !n)
		return ;
	dst->ptr[dst->size++] = *src++;
	if (dst->size == T_BUFFER_SIZE)
		buf_flush(dst);
	buf_write(dst, src, n - 1);
	return ;
}
