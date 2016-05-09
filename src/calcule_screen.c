/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 14:36:28 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/07 10:35:55 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_pt	calcule_screen_pos(t_env *env)
{
	t_pt	screen_pos;

	screen_pos = ft_add(env->pos, env->dir);
	screen_pos = ft_add(screen_pos, ft_dot(-0.5, env->screen_dir));
	return (screen_pos);
}

void		calcule_screen(t_env *env)
{
	env->screen_dir = (t_pt){-(env->dir.y), env->dir.x};
	env->screen_pos = calcule_screen_pos(env);
}
