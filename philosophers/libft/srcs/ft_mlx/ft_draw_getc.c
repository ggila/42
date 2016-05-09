/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_getc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 11:00:07 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 22:30:13 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "ft_mem.h"

int			ft_draw_getc(int x, int y, int *buf, t_image *img)
{
	ft_memcpy(buf, img->data + img->bypp * (y * img->width + x), img->bypp);
	return (0);
}
