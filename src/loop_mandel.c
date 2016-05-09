/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:36:05 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 19:14:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

void	ft_raa(int keycode, t_spec *spec)
{
	if (keycode == KEY_EQU && spec->power < 20 && spec->power > 2)
		spec->power += 1;
	else if (keycode == KEY_MIN && spec->power > 3)
		spec->power -= 1;
	if (spec->fractal == NEWTON)
		ft_get_zero(spec->zero, spec->power);
}

void	ft_key_motion_mandel(int keycode, t_spec *spec)
{
	char sign;

	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		sign = (keycode == KEY_LEFT) ? -1 : 1;
		spec->x_mid += sign * INC_MOVE * spec->x_amp;
	}
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		sign = (keycode == KEY_UP) ? -1 : 1;
		spec->y_mid += sign * INC_MOVE * spec->x_amp;
	}
	else if (keycode == KEY_A || keycode == KEY_S)
	{
		sign = (keycode == KEY_A) ? -1 : 1;
		spec->theta += sign * INC_THETA;
	}
	else if (keycode == KEY_Z || keycode == KEY_X)
	{
		spec->x_amp *= (keycode == KEY_Z) ? 1.1 : 0.9;
		spec->delta = spec->x_amp / (WIF);
	}
}

void	ft_motion_leftmouse_mandel(int x, int y, t_spec *spec)
{
	if (spec->fractal == JULIA)
	{
		if (!(spec->flag & MASK_MOVE))
		{
			spec->flag |= MASK_MOVE;
			spec->x_mouse = x;
			spec->y_mouse = y;
		}
		else
		{
			spec->x_mid -= (x - spec->x_mouse) * spec->delta;
			spec->y_mid -= (y - spec->y_mouse) * spec->delta;
			spec->x_mouse = x;
			spec->y_mouse = y;
		}
	}
}
