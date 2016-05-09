/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 19:02:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 18:29:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

int					ft_mandel(t_spec *spec, int i, int j)
{
	double		theta;
	t_complex	temp;
	t_complex	z;
	t_complex	seed;

	temp.a = spec->x_mid - spec->x_amp / 2 + (i - WIM) * spec->delta;
	temp.b = spec->y_mid - HIM * spec->delta / 2 + j * spec->delta;
	theta = spec->theta;
	seed.a = temp.a * cos(theta) + temp.b * sin(theta);
	seed.b = -temp.a * sin(theta) + temp.b * cos(theta);
	z.a = 0;
	z.b = 0;
	return (ft_eq_mandel(z, seed, spec));
}

int					ft_julia(t_spec *spec, int i, int j)
{
	t_complex	z;
	t_complex	seed;
	int			color;

	z.a = (i - MID_WIF) * spec->delta + spec->x_mid;
	z.b = (j - MID_HIF) * spec->delta + spec->y_mid;
	seed.a = spec->root.a;
	seed.b = spec->root.b;
	color = ft_eq_mandel(z, seed, spec);
	return (color);
}

static int			ft_check_zero(t_complex z, t_spec *spec)
{
	int			i;

	i = -1;
	while (++i < spec->power)
	{
		if ((ABS(z.a - (spec->zero[i]).a) < EPSILON) &&
		(ABS(z.b - (spec->zero[i]).b) < EPSILON))
			return (i);
	}
	return (i);
}

static t_complex	ft_get_next(t_complex z, int n)
{
	t_complex	up;
	t_complex	down;
	t_complex	ret;

	down = ft_pow(z, n - 1);
	up = ft_mult(z, down);
	up.a = ((n - 1) * up.a - 1) / n;
	up.b = ((n - 1) * up.b) / n;
	down = ft_inv(down);
	ret = ft_mult(up, down);
	return (ret);
}

int					ft_newton(t_spec *spec, int i, int j)
{
	t_complex	z;
	int			col[spec->power];
	int			k;
	int			l;

	z.a = spec->x_mid - spec->x_amp / 2 + (i - WIM) * spec->delta;
	z.b = spec->y_mid - HIM * spec->delta / 2 + j * spec->delta;
	k = -1;
	l = ft_check_zero(z, spec);
	while ((++k < spec->nb_it) && (l == spec->power))
	{
		z = ft_get_next(z, spec->power);
		l = ft_check_zero(z, spec);
	}
	k = -1;
	while (++k < spec->power)
		col[k] = ((double)(1 + k) / (1 + spec->power)) *
		ft_set_color(spec, OUT1);
	return (l == spec->power ? ft_set_color(spec, IN) : col[l]);
}
