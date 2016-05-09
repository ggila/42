/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 10:58:18 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 18:16:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

void	ft_init_julia_spec(t_env *env, char fractal)
{
	env->spec.nb_it = NB_IT_JULIA;
	env->spec.x_amp = X_AMP_MANDEL;
	env->spec.x_mid = fractal == 0 ? X_JULIA : -0.80355555;
	env->spec.y_mid = fractal == 0 ? Y_JULIA : 0.0274;
	env->spec.power = fractal == 0 ? 2 : 6;
	env->spec.coef_col[OUT1][GREEN] = fractal == 0 ? 0.55 : 660;
	env->spec.coef_col[OUT1][RED] = fractal == 0 ? 0.55 : 660;
	env->spec.coef_col[OUT1][BLUE] = fractal == 0 ? 0 : 660;
	env->spec.color[IN] = ft_set_color(&(env->spec), IN);
	if (fractal == MEGALIA)
	{
		env->spec.root.a = -0.55;
		env->spec.root.b = 0.84;
	}
	env->spec.delta = fractal == 0 ? env->spec.x_amp / WIF : 0.000015;
}

void	ft_init_mandel_spec(t_env *env, char fractal)
{
	env->spec.nb_it = NB_IT_MANDEL;
	env->spec.theta = THETA_INIT;
	env->spec.x_mid = fractal == 1 ? X_MANDEL : 0.35;
	env->spec.y_mid = Y_MANDEL;
	env->spec.x_amp = fractal == 1 ? X_AMP_MANDEL : 2 * X_AMP_MANDEL / 3;
	env->spec.power = fractal == 1 ? 2 : 6;
	env->spec.coef_col[OUT2][RED] = fractal == 1 ?
		COEF_RED_INIT_MANDEL_OUT2 : 0;
	env->spec.coef_col[OUT1][BLUE] = fractal == 1 ? 0 : 0.5;
	env->spec.coef_col[OUT1][RED] = fractal == 1 ? 0 : 0.5;
	env->spec.coef_col[IN][RED] = fractal == 1 ? 0 : 1;
	env->spec.delta = env->spec.x_amp / WIF;
}

void	ft_init_newton_spec(t_env *env, char fractal)
{
	(void)fractal;
	env->spec.nb_it = NB_IT_NEWTON;
	env->spec.power = POWER;
	env->spec.x_mid = X_NEWTON;
	env->spec.y_mid = Y_NEWTON;
	env->spec.x_amp = X_AMP_NEWTON;
	ft_get_zero(env->spec.zero, env->spec.power);
	env->spec.coef_col[OUT1][BLUE] = COEF_BLUE_INIT_JULIA_OUT2;
	env->spec.coef_col[OUT1][GREEN] = COEF_BLUE_INIT_JULIA_OUT2;
	env->spec.coef_col[OUT1][RED] = COEF_BLUE_INIT_JULIA_OUT2;
	env->spec.coef_col[IN][RED] = 0.2;
	env->spec.delta = env->spec.x_amp / WIF;
}

void	ft_init_spec(t_env *env, char fractal)
{
	static t_ft_env_init_fract	ft_fractenv[3] = {

	ft_init_julia_spec, ft_init_mandel_spec, ft_init_newton_spec};
	ft_bzero(&(env->spec), sizeof(t_spec));
	env->spec.root.a = 0;
	env->spec.root.b = 0;
	env->spec.fast = 0;
	env->spec.modif = IN;
	ft_fractenv[fractal % 3](env, fractal);
	env->spec.fractal = fractal;
}
