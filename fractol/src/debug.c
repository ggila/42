/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 11:33:04 by ggilaber          #+#    #+#             */
/*   Updated: 2015/03/18 18:28:22 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_define.h"
#include "fractol_struct.h"
#include "fractol_proto.h"

static void	ft_print_color(t_env env, char i)
{
	if (i == IN)
		ft_putstr("\ncolor[IN] :   ");
	if (i == OUT1)
		ft_putstr("\ncolor[OUT1] : ");
	if (i == OUT2)
		ft_putstr("\ncolor[OUT2] : ");
	ft_putnbr((int)(100 * env.spec.coef_col[(int)i][RED]));
	ft_putstr(" | ");
	ft_putnbr((int)(100 * env.spec.coef_col[(int)i][GREEN]));
	ft_putstr(" | ");
	ft_putnbr((int)(100 * env.spec.coef_col[(int)i][BLUE]));
}

static void	ft_print_double(t_env env)
{
	ft_putstr("\nx_mid (*100) : ");
	ft_putnbr((int)(100 * env.spec.x_mid));
	ft_putstr("\ny_mid (*100) : ");
	ft_putnbr((int)(100 * env.spec.y_mid));
	ft_putstr("\nroot.a (*100) : ");
	ft_putnbr((int)(100 * env.spec.root.a));
	ft_putstr("\nroot.b (*100) :");
	ft_putnbr((int)(100 * env.spec.root.b));
	ft_putstr("\n");
	ft_putstr("\nx_delta (*10^5) :");
	ft_putnbr((int)(100000 * env.spec.delta));
	ft_putstr("\nx_amp (*100) :");
	ft_putnbr((int)(100 * env.spec.x_amp));
	ft_putstr("\ntheta (*100) :");
	ft_putnbr((int)(100 * env.spec.theta));
	ft_putstr("\n");
}

void		ft_print_spec(t_env env)
{
	ft_putstr("\nfractal : ");
	ft_putnbr(env.spec.fractal);
	ft_putstr("\nnb_it   : ");
	ft_putnbr(env.spec.nb_it);
	ft_putstr("\npower   : ");
	ft_putnbr(env.spec.power);
	ft_print_double(env);
	ft_print_color(env, IN);
	ft_print_color(env, OUT1);
	ft_print_color(env, OUT2);
	ft_putstr("\n");
}
