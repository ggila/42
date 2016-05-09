/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eq.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 03:35:05 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/17 11:26:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

int	ft_grad(t_spec *spec, int i, double norm)
{
	unsigned char	base;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	int				color;

	base = 4 * (((i + 1.0 - (log(log(norm)) / log(2))) * 255.0)
		/ spec->nb_it) / 5 + 51;
	red = base * spec->coef_col[OUT1][RED];
	green = base * spec->coef_col[OUT1][GREEN];
	blue = base * spec->coef_col[OUT1][BLUE];
	color = (red << 16) + (green << 8) + blue;
	red = -base * spec->coef_col[OUT2][RED];
	green = -base * spec->coef_col[OUT2][GREEN];
	blue = -base * spec->coef_col[OUT2][BLUE];
	color += (red << 16) + (green << 8) + blue;
	return (color);
}

int	ft_eq_mandel(t_complex z, t_complex seed, t_spec *spec)
{
	t_complex	ret;
	double		norm;
	int			i;
	int			color;

	i = -1;
	ret.a = z.a;
	ret.b = z.b;
	norm = ft_norm(ret);
	while (++i < spec->nb_it && norm < MAX_MOD)
	{
		ret = ft_pow(ret, spec->power);
		ret.a += seed.a;
		ret.b += seed.b;
		norm = ft_norm(ret);
	}
	color = (i == spec->nb_it) ? spec->color[IN] : ft_grad(spec, i, norm);
	return (color);
}
