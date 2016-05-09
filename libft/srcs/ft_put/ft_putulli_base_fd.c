/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulli_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:33:19 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/06 20:58:38 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"
#include "ft_str.h"

void	ft_putulli_base_fd(t_ulli nb, char const *s_base, int fd)
{
	t_ulli		base;
	t_ulli		div;
	t_ulli		temp;

	div = 1;
	if ((base = ft_strlen(s_base)) < 2)
		return ;
	while (nb / div >= base)
		div *= base;
	while (div > 0)
	{
		temp = nb / div;
		ft_putchar_fd(s_base[temp], fd);
		nb %= div;
		div /= base;
	}
}
