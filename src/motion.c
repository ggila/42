/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 23:37:23 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 18:17:00 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

int	ft_motion_leftmouse(int x, int y, t_env *env)
{
	const t_ft_mouse	ft_motion_tab[3] = {

	ft_motion_leftmouse_julia, ft_motion_leftmouse_mandel
	, ft_motion_leftmouse_mandel};
	ft_motion_tab[env->spec.fractal % 3](x, y, &(env->spec));
	env->flag |= MASK_DRAW;
	return (OK);
}

int	ft_motion_key(int keycode, t_env *env)
{
	const t_ft_key	ft_key_tab[3] = {

	ft_key_motion_julia, ft_key_motion_mandel, ft_key_motion_mandel};
	ft_key_tab[env->spec.fractal % 3](keycode, &(env->spec));
	env->flag |= MASK_DRAW;
	return (OK);
}
