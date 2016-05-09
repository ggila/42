/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:02:47 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 19:18:01 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

void ft_key_motion_julia(int keycode, t_spec *spec)
{
	int sign;

	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		sign = (keycode == KEY_LEFT) ? -1 : 1;
		spec->x_amp = WIF * spec->delta;
		spec->x_mid += sign * INC_MOVE * spec->x_amp;
	}
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		sign = (keycode == KEY_UP) ? -1 : 1;
		spec->x_amp = WIF * spec->delta;
		spec->y_mid += sign * INC_MOVE * spec->x_amp;
	}
	else if (keycode == KEY_Z || keycode == KEY_X)
	{
		spec->delta *= (keycode == KEY_Z) ? INC_DELTA : 1 / INC_DELTA;
		ft_putnbr(keycode);
	}
}

void ft_motion_leftmouse_julia(int x, int y, t_spec *spec)
{
	if (spec->fractal == JULIA)
	{
		spec->root.a = (x - MID_WIF) * spec->delta + spec->x_mid;
		spec->root.b = (y - MID_HIF) * spec->delta + spec->y_mid;
	}
}
