/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 19:25:02 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 19:13:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

static int	ft_check_inputs(int ac, char **av)
{
	int			i;
	const char	*str[] = {

	"Julia", "Mandelbrot", "Newton", "Megalia", "Megabrot",
	"1", "2", "3", "4", "5",
	"mandel", "julia", "newton", "megalia", "megabrot"};
	av++;
	if (ac == 2)
	{
		i = 0;
		while (i < 15)
		{
			if (ft_strequ(*av, str[i]))
				return (i % 5);
			i++;
		}
	}
	ft_putendl("1/ Julia (julia)\n2/ Mandelbrot (mandel)\n3/ Newton (newton)"
	"\n4/ Megalia (megalia)\n5/ Megabrot (megabrot)");
	exit(OK);
}

static int	ft_init_env(t_env *env, char fractal)
{
	if (!(env->mlx = mlx_init()))
		return (KO);
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, TITLE)))
		return (KO);
	if ((env->img.img = mlx_new_image(env->mlx, WIDTH, HEIGHT)))
		env->img.data = mlx_get_data_addr(env->img.img, &(env->img.bpp),
		&(env->img.size_line), &(env->img.endian));
	if (!env->img.img || !env->img.data)
		return (KO);
	env->flag = 0;
	ft_init_spec(env, fractal);
	return (OK);
}

int			main(int ac, char **av)
{
	t_env	env;
	char	fractal;

	fractal = ft_check_inputs(ac, av);
	ft_bzero(&env, sizeof(t_env));
	av++;
	if (ft_init_env(&env, fractal) == KO)
		return (KO);
	mlx_expose_hook(env.win, ft_expose_hook, &env);
	mlx_mouse_hook(env.win, ft_mouse_hook, &env);
	mlx_hook(env.win, MotionNotify, PointerMotionMask,
	ft_motion_leftmouse, &env);
	mlx_hook(env.win, KeyPress, KeyPressMask, ft_motion_key, &env);
	mlx_hook(env.win, KeyRelease, KeyReleaseMask, ft_key_hook, &env);
	mlx_loop_hook(env.mlx, ft_loop_hook, &env);
	mlx_loop(env.mlx);
	return (OK);
}
