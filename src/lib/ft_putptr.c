/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 13:08:18 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/02 15:27:47 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#define MASK 0xf000000000000000

void	ft_putptr(void *ptr)
{
	char					str[16];
	int						i;
	char					add[17];
	long long unsigned int	p;

	add[16] = '\0';
	ft_memcpy(str, "0123456789abcdef", 17);
	p = (long long unsigned int)ptr;
	i = -1;
	while (++i < 16)
	{
		add[i] = str[(p & MASK) >> 60];
		p = p << 4;
	}
	i = 0;
	while (i < 15 && add[i] == '0')
		i++;
	ft_putstr("0x");
	ft_putstr(add + i);
}
