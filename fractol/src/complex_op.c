/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 11:20:04 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/17 11:24:02 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

double		ft_norm(t_complex z)
{
	return (sqrt(z.a * z.a + z.b * z.b));
}

t_complex	ft_inv(t_complex z)
{
	double	temp;

	temp = z.a;
	z.a = z.a / (z.a * z.a + z.b * z.b);
	z.b = -z.b / (temp * temp + z.b * z.b);
	return (z);
}

t_complex	ft_mult(t_complex y, t_complex z)
{
	t_complex ret;

	ret.a = y.a * z.a - y.b * z.b;
	ret.b = y.a * z.b + y.b * z.a;
	return (ret);
}

t_complex	ft_pow(t_complex z, int n)
{
	if (n == 1)
		return (z);
	else if (n % 2)
		return (ft_mult(z, ft_pow(z, n - 1)));
	else
		return (ft_mult(ft_pow(z, n / 2), ft_pow(z, n / 2)));
}

void		ft_get_zero(t_complex zero[20], int n)
{
	int i;

	i = -1;
	while (++i < n + 1)
	{
		zero[i].a = cos(2 * i * PI / n);
		zero[i].b = sin(2 * i * PI / n);
	}
}
