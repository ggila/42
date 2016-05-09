/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 09:42:16 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/23 14:52:14 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	get_color(char face)
{
	if (face == NORTH)
		return (NORTH_COLOR);
	if (face == SOUTH)
		return (SOUTH_COLOR);
	if (face == EST)
		return (EST_COLOR);
	if (face == WEST)
		return (WEST_COLOR);
	return (0);
}

static void	draw_ray(t_env *env, t_feed feedback, int i)
{
	int	j;
	int	ground;
	int	sky;
	int	color;

	j = -1;
	ground = get_ground_limit(feedback.dist);
	sky = get_sky_limit(feedback.dist);
	color = GROUND_COLOR;
	while (IM_HEIGHT - ++j > sky)
		ft_memmove((env->img.data + (env->img.bpp / 8) *
				(i + j * IM_WIDTH)), &color, env->img.bpp / 8);
	color = get_color(feedback.face);
	while (IM_HEIGHT - j > ground)
		ft_memmove((env->img.data + (env->img.bpp / 8) *
				(i + j++ * IM_WIDTH)), &color, env->img.bpp / 8);
	color = SKY_COLOR;
	while (IM_HEIGHT - j)
		ft_memmove((env->img.data + (env->img.bpp / 8) *
				(i + j++ * IM_WIDTH)), &color, env->img.bpp / 8);
}

void		draw_map(t_env *env)
{
	int	i;
	int j;
	int	color;

	j = -1;
	while (++j < 100)
	{
		i = -1;
		while (++i < 100)
		{
			color = g_map[j / 5][i / 5] == '1' ? RED : WHITE;
			ft_memmove((env->img.data + (env->img.bpp / 8) *
					(i + j * IM_WIDTH)), &color, env->img.bpp / 8);
		}
	}
}

void		draw_pos(t_pt pos, t_env *env)
{
	int	i;
	int j;
	int	color;

	color = 0x00005500;
	j = -3;
	while (++j < 3)
	{
		i = -3;
		while (++i < 3)
		{
			ft_memmove((env->img.data + (env->img.bpp / 8) *
					(((int)(5 * pos.x)) + i + ((int)(5 * pos.y) + j)
					* IM_WIDTH)), &color, env->img.bpp / 8);
		}
	}
}

void		draw_image(t_env *env)
{
	int		i;
	t_pt	screen_step;
	t_pt	target;
	t_pt	ray_dir;
	t_feed	feedback;

	calcule_screen(env);
	screen_step = ft_dot(1. / IM_WIDTH, env->screen_dir);
	target = env->screen_pos;
	i = -1;
	while (++i < IM_WIDTH)
	{
		ray_dir = ft_add(target, ft_dot(-1, env->pos));
		ray_dir = ft_dot(1. / ft_norm(ray_dir), ray_dir);
		feedback = throw_ray(env->pos, ray_dir,
				env->ang, ((double)IM_WIDTH / 2 - i) / IM_WIDTH);
		target = ft_add(target, screen_step);
		draw_ray(env, feedback, i);
	}
}
