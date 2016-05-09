/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 09:42:16 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 18:19:15 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

static void	ft_print_menu_background(t_env *env, int *color,
t_ft_get_pix ft_fractal)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIM)
	{
		j = -1;
		while (++j < HIM)
		{
			if (i < IM_MARGIN ||
				j < IM_MARGIN || j > (HIM - IM_MARGIN) ||
				((j > IM_MARGIN + HIM / 3) && (j <= IM_MARGIN + 2 * HIM / 3)))
			{
				*color = ft_fractal(&(env->spec), i, j);
				ft_memmove((env->img.data + (env->img.bpp / 8) *
					(i + j * WIDTH)), color, env->img.bpp / 8);
			}
		}
	}
}

static void	ft_print_in_menu(t_env *env, int *color, int i, int j)
{
	int	color2;

	if ((i > WIM) && TOMENU(j) && ((i % 3) == 0 || (j % 3) == 0))
	{
		color2 = ~(*color);
		ft_memmove((env->img.data + (env->img.bpp / 8) *
			(WIM - (i - WIM) / 3 + IM_MARGIN + (j / 3 + IM_MARGIN) * WIDTH)),
				color, env->img.bpp / 8);
		ft_memmove((env->img.data + (env->img.bpp / 8) *
			(((i - WIM) / 3 + IM_MARGIN) + (j / 3 + 2 * HIM / 3 - IM_MARGIN)
				* WIDTH)), &color2, env->img.bpp / 8);
	}
}

static void	ft_print_fractal(t_env *env, int *color, t_ft_get_pix ft_fractal)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WI)
	{
		j = -1;
		while (++j < HIF)
		{
			*color = ft_fractal(&(env->spec), i, j);
			if (env->spec.fractal == MANDEL)
				ft_print_in_menu(env, color, i, j);
			ft_memmove((env->img.data + (env->img.bpp / 8) *
				(i + j * WIDTH)), color, env->img.bpp / 8);
		}
	}
}

void		ft_iterate(t_env *env)
{
	int					color;
	int					fractal;
	static t_ft_get_pix	ft_fractal_pix[3] = {

	ft_julia, ft_mandel, ft_newton};
	fractal = (int)env->spec.fractal;
	if (env->spec.fractal % 3 == MANDEL)
		ft_print_menu_background(env, &color, ft_fractal_pix[fractal % 3]);
	ft_print_fractal(env, &color, ft_fractal_pix[fractal % 3]);
	return ;
}
