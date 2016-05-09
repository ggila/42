/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 03:36:43 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_print_flag(char n)
{
	ft_putendl("\n--------------------------------");
	if (n != 2)
	{
		ft_putstr("g_flag\n");
		ft_putstr("\nMASK_TOTAL : ");
		ft_putnbr(!!(g_flag & MASK_TOTAL));
		ft_putstr("\nMASK_FLAG : ");
		ft_putnbr(!!(g_flag & MASK_FLAG));
		ft_putstr("\nMASK_DEBUG : ");
		ft_putnbr(!!(g_flag & MASK_DEBUG));
		ft_putendl("\n--------------------------------");
	}
	if (n != 1)
	{
		ft_putstr("g_flag_op\n");
		ft_putstr("\nMASK_EQUAL : ");
		ft_putnbr(!!(g_flag_op & MASK_EQUAL));
		ft_putstr("\nMASK_MINUS : ");
		ft_putnbr(!!(g_flag_op & MASK_MINUS));
		ft_putendl("\n--------------------------------");
	}
}

void	ft_put_double(double d)
{
	int n;

	n = d;
	if (n == 0 && d <= 0)
		ft_putchar('-');
	ft_putnbr(n);
	if (n - d)
	{
		ft_putchar('.');
		ft_putnbr(ABS(100 * (d - n)));
	}
}

void	ft_put_monom(int coef)
{
	int	n;

	n = g_monom[coef];
	if (n >= 0 && coef != 3)
		ft_putchar('+');
	ft_put_double(g_monom[coef]);
	if (coef)
	{
		ft_putstr(" * ");
		ft_putchar(g_x);
		if (coef > 1)
		{
			ft_putchar('^');
			ft_putnbr(coef);
		}
	}
	ft_putstr("\n");
	while (coef++ - 4)
		ft_putstr("\t");
}

void	ft_put_all_monom(void)
{
	int		i;
	char	flag;

	i = 4;
	flag = 0;
	while (flag == 0 && --i >= 0)
		if (g_monom[i] != 0)
			flag++;
	ft_putstr("-------------------------------------------------\n");
	ft_putstr("reduced form (degree ");
	ft_putnbr(i);
	ft_putstr(")\n");
	i = 4;
	while (--i >= 0)
		if (g_monom[i])
			ft_put_monom(i);
	if (!flag)
		ft_putstr("0 ");
	ft_putendl("= 0");
	ft_putstr("-------------------------------------------------\n");
}
