/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 23:28:58 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/23 13:30:55 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_expose_hook(t_env *env)
{
	env->flag |= MASK_DRAW;
	return (OK);
}

int	ft_loop_hook(t_env *env)
{
	if (env->flag & MASK_DRAW)
	{
		if (env->flag & MASK_MAP)
			draw_modif(env);
		else
		{
			draw_image(env);
			draw_map(env);
			draw_pos(env->pos, env);
		}
		mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
		env->flag &= ~MASK_DRAW;
	}
	return (OK);
}
