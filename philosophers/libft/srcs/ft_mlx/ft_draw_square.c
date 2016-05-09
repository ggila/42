/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 12:12:37 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 22:28:24 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int		ft_draw_square(t_pix p, t_pix delta, t_image *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < delta.y)
	{
		delta.c = ((p.y + i) * img->width + p.x) * img->bypp;
		j = 0;
		while (j < img->bypp * delta.x)
		{
			((unsigned char *)(img->data + delta.c))[j] =
				((unsigned char *)(&(p.c)))[j % img->bypp];
			j++;
		}
		i++;
	}
	return (0);
}
