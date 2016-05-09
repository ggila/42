/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:57:02 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 18:28:50 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

int	ft_is_key(int key)
{
	return (key == KEYPAD_1 || key == KEYPAD_2 || key == KEYPAD_3
	|| key == KEYPAD_7 || key == KEYPAD_8 || key == KEYPAD_9
	|| key == KEYPAD_4 || key == KEYPAD_5 || key == KEYPAD_6
	|| key == KEYPAD_0);
}

int	ft_is_dir(int key)
{
	return (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT
	|| key == KEY_RIGHT);
}

int	ft_is_num(int key)
{
	return (key == KEY_1 || key == KEY_2 || key == KEY_5
	|| key == KEY_3 || key == KEY_4);
}

int	ft_set_color(t_spec *spec, int i)
{
	return (((int)(255 * spec->coef_col[i][RED]) << 16) +
	((int)(255 * spec->coef_col[i][GREEN]) << 8)
	+ (int)(255 * spec->coef_col[i][BLUE]));
}
