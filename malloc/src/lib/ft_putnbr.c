/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:22:23 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/02 15:08:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putnbr(-214748364);
			ft_putnbr(8);
			return ;
		}
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + (n % 10));
	}
	else
		ft_putchar('0' + n);
}
