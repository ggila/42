/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 23:37:23 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/23 15:01:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_pt		ft_move(t_pt pos, t_pt dir, int c)
{
	t_pt	new;

	new = ft_add(pos, c == KEY_UP ? ft_dot(0.3, dir) : ft_dot(-0.3, dir));
	if (g_map[(int)new.y][(int)pos.x] == '1')
		new.y = pos.y;
	if (g_map[(int)pos.y][(int)new.x] == '1')
		new.x = pos.x;
	return (new);
}

t_pt		ft_rotate(int *i, int c)
{
	t_pt	new;

	if (c == KEY_LEFT)
		*i = (*i + 100) % 3600;
	if (c == KEY_RIGHT)
		*i = *i >= 100 ? *i - 100 : 3500 + *i;
	new = (t_pt){g_cos[*i], g_sin[*i]};
	return (new);
}

static void	map_modif(int keycode)
{
	if (keycode < KEY_DOWN)
		g_po[X] += keycode == KEY_RIGHT ? 1 : -1;
	if (keycode >= KEY_DOWN)
		g_po[Y] += keycode == KEY_DOWN ? 1 : -1;
	if (g_po[X] < 1)
		g_po[X] = 1;
	if (g_po[X] > 18)
		g_po[X] = 18;
	if (g_po[Y] < 1)
		g_po[Y] = 1;
	if (g_po[Y] > 18)
		g_po[Y] = 18;
}

int			ft_motion_key(int keycode, t_env *env)
{
	static int i = 1;

	if (keycode == KEY_M)
	{
		g_po[X] = 1;
		g_po[Y] = 1;
		env->flag |= MASK_MAP;
	}
	else if (keycode >= KEY_LEFT && keycode <= KEY_UP && env->flag & MASK_MAP)
		map_modif(keycode);
	else if (keycode == KEY_SHIFT && env->flag & MASK_MAP)
		g_map[g_po[Y]][g_po[X]] = g_map[g_po[Y]][g_po[X]] == '1' ? '0' : '1';
	else if (keycode == KEY_RETURN && env->flag & MASK_MAP)
		env->flag &= (~MASK_MAP);
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
		env->pos = ft_move(env->pos, env->dir, keycode);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		env->dir = ft_rotate(&i, keycode);
		env->ang = i;
	}
	else if (keycode == KEY_ESC)
		exit(0);
	env->flag |= MASK_DRAW;
	return (OK);
}
