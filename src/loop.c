/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 23:28:58 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 17:13:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

int	ft_expose_hook(t_env *env)
{
	env->flag |= MASK_DRAW;
	return (OK);
}

int	ft_key_hook(int keycode, t_env *env)
{
	t_spec	*spec;

	spec = &(env->spec);
	if (keycode == KEY_ESC)
		exit (0);
	else if (ft_is_num(keycode))
		ft_change_fractal(env, keycode);
	else if (ft_is_key(keycode))
		ft_change_color(spec, keycode);
	else if (keycode == KEYPAD_PLUS || keycode == KEYPAD_MINUS)
		spec->nb_it += ((keycode == KEYPAD_PLUS) ? 1 : -1) * INC_NB_IT;
	else if (keycode == KEY_R)
		ft_init_spec(env, env->spec.fractal);
	ft_raa(keycode, spec);
	env->flag |= MASK_DRAW;
	return (OK);
}

int	ft_mouse_hook(int button, int x, int y, t_env *env)
{
	double			delta_old;

	if (button == 4 || button == 5)
	{
		delta_old = env->spec.delta;
		env->spec.delta *= (button == 5) ? INC_DELTA : 1 / INC_DELTA;
		env->spec.x_amp = WIF * env->spec.delta;
		env->spec.x_mid += (x - MID_WIF) * (delta_old - env->spec.delta);
		env->spec.y_mid += (y - MID_HIF) * (delta_old - env->spec.delta);
	}
	if (button == 3)
	{
		env->spec.x_mid += (x - MID_WIF) * env->spec.delta;
		env->spec.y_mid += (y - HIF / 2) * env->spec.delta;
	}
	env->flag |= MASK_DRAW;
	return (OK);
}

int	ft_loop_hook(t_env *env)
{
	if (env->flag & MASK_DRAW)
	{
		ft_print_spec(*env);
		ft_iterate(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
		env->flag &= ~MASK_DRAW;
	}
	return (OK);
}
