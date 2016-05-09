/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 10:52:57 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 22:28:14 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int			ft_draw_img(t_pix p, t_image *dst, t_image *src)
{
	int		i;
	int		j;
	t_pix	offset;

	i = 0;
	if (dst->bypp != src->bypp)
		return (-1);
	while (i < src->height)
	{
		offset.x = ((p.y + i) * dst->width + p.x) * dst->bypp;
		offset.y = i * src->width * dst->bypp;
		j = 0;
		while (j < src->bypp * src->width)
		{
			((unsigned char *)(dst->data + offset.x))[j] =
				((unsigned char *)(src->data + offset.y))[j];
			j++;
		}
		i++;
	}
	return (0);
}
