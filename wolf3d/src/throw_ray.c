/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feedback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 15:49:38 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/23 15:00:55 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_ray_step(t_pt pos, int ang, int map_step[2]
		, double ray_step[2])
{
	double delta_x;
	double delta_y;

	delta_x = map_step[X] > 0 ? ((int)pos.x + 1) - pos.x : pos.x
		- (int)pos.x;
	delta_y = map_step[Y] > 0 ? ((int)pos.y + 1) - pos.y : pos.y
		- (int)pos.y;
	ray_step[X] = delta_x / ABS(g_cos[ang]);
	ray_step[Y] = delta_y / ABS(g_sin[ang]);
}

static void	calcule_ray_pos(int ray_pos[2], double dist[2]
		, int map_step[2], int min)
{
	int max;

	(void)dist;
	max = min == 'X' ? 'Y' : 'X';
	ray_pos[min] += map_step[min];
	ray_pos[max] += map_step[max];
}

static void	check_boundary(int pos[2])
{
	if (pos[0] < 0 || pos[0] > 20 || pos[1] < 0 || pos[1] > 20)
	{
		pos[0] = 0;
		pos[1] = 0;
	}
}

static char	throw(t_pt pos, t_ray *ray, int ang)
{
	int		min;
	int		max;
	double	dist[2];
	int		ray_pos[2];

	dist[X] = 0;
	dist[Y] = 0;
	ray_pos[X] = (int)pos.x;
	ray_pos[Y] = (int)pos.y;
	while (g_map[ray_pos[Y]][ray_pos[X]] != '1')
	{
		min = (ray->ray_step[X] < ray->ray_step[Y]) ? X : Y;
		max = (min == X) ? Y : X;
		calcule_ray_pos(ray_pos, dist, ray->map_step, min);
		dist[X] += ray->ray_step[min] * ABS(g_cos[ang]);
		dist[Y] += ray->ray_step[min] * ABS(g_sin[ang]);
		ray->len += ray->ray_step[min];
		ray->ray_step[max] -= ray->ray_step[min];
		ray->ray_step[min] = ray->ray_mapcase[min];
		check_boundary(ray_pos);
	}
	if (min == X)
		return (ray->map_step[X] > 0 ? EST : WEST);
	else
		return (ray->map_step[Y] > 0 ? SOUTH : NORTH);
}

t_feed		throw_ray(t_pt pos, t_pt ray_dir, int ang, double d_ang)
{
	t_feed	new;
	t_ray	ray;

	ray.len = 0;
	ang += (int)(10 * (atan(d_ang) * 180 / PI));
	if (ang > 3600)
		ang -= 3600;
	else if (ang < 0)
		ang += 3600;
	else if (ang == 0 || ang == 3600)
		ang = 1;
	(void)ray_dir;
	ray.map_pos[X] = (int)pos.x;
	ray.map_pos[Y] = (int)pos.y;
	ray.map_step[X] = ang < 900 || ang > 2700 ? 1 : -1;
	ray.map_step[Y] = ang < 1800 ? 1 : -1;
	init_ray_step(pos, ang, ray.map_step, ray.ray_step);
	ray.ray_mapcase[X] = 1 / ABS(g_cos[ang]);
	ray.ray_mapcase[Y] = 1 / ABS(g_sin[ang]);
	new.face = throw(pos, &ray, ang);
	new.dist = ray.len;
	return (new);
}
