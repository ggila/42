/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 14:45:47 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/02 15:06:39 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_printptr(void *p1, void *p2)
{
	ft_putstr("\t|_");
	ft_putptr(p1);
	ft_putstr("\t\tsize:");
	ft_putptr(p2);
	ft_putstr("\n");
}

void	ft_printnbr(void *p1, int n)
{
	ft_putstr("\t|_");
	ft_putptr(p1);
	ft_putstr("\t\tsize:");
	ft_putnbr(n);
	ft_putstr("\n");
}

void	ft_printarea(void *p1, void *p2, int n)
{
	ft_putstr("\t|   ...\t\t\t\t\t\t");
	ft_putptr(p1);
	ft_putstr(" - ");
	ft_putptr(p2);
	ft_putstr("\t\t(");
	ft_putnbr(n);
	ft_putstr(")\n");
}
