/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 12:12:48 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 22:31:30 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int			ft_draw_pix(t_pix p, t_image *image)
{
	int		i;
	int		offset;

	if (p.x < 0 || p.y < 0 || p.x >= image->width || p.y >= image->height)
		return (0);
	offset = (p.y * image->width + p.x) * image->bypp;
	i = 0;
	while (i < image->bypp)
	{
		((unsigned char *)(image->data + offset))[i] =
			((unsigned char *)(&(p.c)))[i];
		i++;
	}
	return (0);
}
