/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 19:03:26 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 19:20:45 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

void		ft_change_fractal(t_env *env, int keycode)
{
	if (keycode == KEY_1)
		ft_init_spec(env, JULIA);
	else if (keycode == KEY_2)
		ft_init_spec(env, MANDEL);
	else if (keycode == KEY_3)
		ft_init_spec(env, NEWTON);
	else if (keycode == KEY_4)
		ft_init_spec(env, MEGALIA);
	else if (keycode == KEY_5)
		ft_init_spec(env, MEGABROT);
}

static void	ft_which_color(t_spec *spec, int keycode)
{
	if (keycode == KEYPAD_4)
		spec->modif = IN;
	if (keycode == KEYPAD_5)
		spec->modif = OUT1;
	if (keycode == KEYPAD_6)
		spec->modif = OUT2;
}

static void	ft_random_color(t_spec *spec, int keycode)
{
	if (keycode == KEYPAD_0)
	{
		spec->coef_col[IN][RED] += 0.3;
		spec->coef_col[IN][GREEN] -= 0.1;
		spec->coef_col[IN][BLUE] += 0.1;
		spec->coef_col[OUT1][RED] += 5;
		spec->coef_col[OUT1][GREEN] += 5;
		spec->coef_col[OUT1][BLUE] += 5;
	}
}

void		ft_change_color(t_spec *spec, int keycode)
{
	int sign;
	int i;

	ft_which_color(spec, keycode);
	i = spec->modif;
	if (keycode == KEYPAD_1 || keycode == KEYPAD_7)
	{
		sign = (keycode == KEYPAD_7) ? 1 : -1;
		spec->coef_col[i][RED] += sign * INC_COLOR;
	}
	else if (keycode == KEYPAD_2 || keycode == KEYPAD_8)
	{
		sign = (keycode == KEYPAD_8) ? 1 : -1;
		spec->coef_col[i][GREEN] += sign * INC_COLOR;
	}
	else if (keycode == KEYPAD_3 || keycode == KEYPAD_9)
	{
		sign = (keycode == KEYPAD_9) ? 1 : -1;
		spec->coef_col[i][BLUE] += sign * INC_COLOR;
	}
	ft_random_color(spec, keycode);
	spec->color[IN] = ft_set_color(spec, IN);
}
