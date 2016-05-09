/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeansaglio <saglio.j@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 15:12:17 by jeansaglio        #+#    #+#             */
/*   Updated: 2015/09/05 12:33:12 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buffer.h"
#include "ft_str.h"

void			buf_putstr(t_buffer *dst, char *str)
{
	if (!dst || !str)
		return ;
	buf_write(dst, str, ft_strlen(str));
	return ;
}
