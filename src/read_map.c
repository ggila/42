/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/03 18:31:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/07 10:35:55 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		read_map(void)
{
	int		fd;
	char	b;
	int		x;
	int		y;

	if ((fd = open("map", O_RDONLY)) == -1)
		return (KO);
	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			read(fd, &b, 1);
			if (!ft_strchr("01", b))
				return (KO);
			g_map[y][x] = b;
			x++;
		}
		read(fd, &b, 1);
		if (b != '\n')
			return (KO);
		y++;
	}
	return (OK);
}
