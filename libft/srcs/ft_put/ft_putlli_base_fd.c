/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlli_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:33:19 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/06 20:55:17 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"
#include "ft_str.h"

void	ft_putlli_base_fd(t_lli nb, char const *s_base, int fd)
{
	t_lli		base;
	t_lli		div;
	t_lli		temp;

	div = 1;
	if ((base = ft_strlen(s_base)) < 2)
		return ;
	if (nb < 0)
		ft_putchar_fd('-', fd);
	while ((nb / div >= base) || (nb / div <= -base))
		div *= base;
	while (div > 0)
	{
		temp = (nb < 0) ? -(nb / div) : (nb / div);
		ft_putchar_fd(s_base[temp], fd);
		nb %= div;
		div /= base;
	}
}
