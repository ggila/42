/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_modif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 13:31:20 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/23 15:00:07 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_back(t_env *env)
{
	int i;
	int j;
	int color;

	color = 0;
	j = -1;
	while (++j < 400)
	{
		i = -1;
		while (++i < 100)
		{
			ft_memmove((env->img.data + (env->img.bpp / 8) *
					(i + j * IM_WIDTH)), &color, env->img.bpp / 8);
			ft_memmove((env->img.data + (env->img.bpp / 8) *
					(500 + i + j * IM_WIDTH)), &color, env->img.bpp / 8);
		}
	}
}

static void	draw_po(t_env *env)
{
	int i;
	int j;
	int color;

	color = 0x00FFFFFF;
	j = -1;
	while (++j < 20)
	{
		i = -1;
		while (++i < 20)
			ft_memmove((env->img.data + (env->img.bpp / 8) *
					(100 + 20 * g_po[X] + i + (20 * g_po[Y] + j) * IM_WIDTH))
					, &color, env->img.bpp / 8);
	}
}

void		draw_modif(t_env *env)
{
	int i;
	int j;
	int color;

	draw_back(env);
	j = -1;
	while (++j < 400)
	{
		i = -1;
		while (++i < 400)
		{
			color = g_map[j / 20][i / 20] == '1' ? 0x00555555 : 0;
			ft_memmove((env->img.data + (env->img.bpp / 8) *
				(100 + i + j * IM_WIDTH)), &color, env->img.bpp / 8);
		}
	}
	draw_po(env);
}
