/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 19:25:02 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/23 11:32:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	sincos(void)
{
	int		i;
	double	ang;

	i = -1;
	ang = 0;
	while (++i < 3600)
	{
		g_cos[i] = cos(ang);
		g_sin[i] = sin(ang);
		ang += 2 * PI / 3600;
	}
}

static int	ft_init_env(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (KO);
	if (!(env->win = mlx_new_window(env->mlx, IM_WIDTH, IM_HEIGHT, TITLE)))
		return (KO);
	if ((env->img.img = mlx_new_image(env->mlx, IM_WIDTH, IM_HEIGHT)))
		env->img.data = mlx_get_data_addr(env->img.img, &(env->img.bpp),
				&(env->img.size_line), &(env->img.endian));
	if (!env->img.img || !env->img.data)
		return (KO);
	sincos();
	env->flag = MASK_DRAW;
	env->pos.x = MAP_WIDTH / 2 + 0.5;
	env->pos.y = MAP_HEIGHT / 2 + 0.5;
	env->dir.x = g_cos[0];
	env->dir.y = g_sin[0];
	env->ang = 1;
	return (OK);
}

int			main(void)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	if (read_map() == KO || ft_init_env(&env) == KO)
		return (KO);
	mlx_expose_hook(env.win, ft_expose_hook, &env);
	ft_loop_hook(&env);
	mlx_hook(env.win, KeyPress, KeyPressMask, ft_motion_key, &env);
	mlx_loop_hook(env.mlx, ft_loop_hook, &env);
	mlx_loop(env.mlx);
	return (OK);
}
