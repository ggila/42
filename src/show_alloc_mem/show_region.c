/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 16:51:53 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/02 17:38:47 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		printallocatedblock(void *ptr)
{
	void	*end;
	size_t	size;

	size = *(size_t*)ptr - 2 * sizeof(size_t);
	end = ADD(ptr, *(size_t*)ptr - sizeof(size_t));
	ft_putptr(ADD(ptr, sizeof(size_t)));
	ft_putstr(" - ");
	ft_putptr(end);
	ft_putstr(" : ");
	ft_putnbr(size);
	ft_putstr(" octets\n");
}

void			show_region(t_reg *reg)
{
	void	*ptr;
	void	*end_region;
	size_t	block_size;
	size_t	end_block;

	while (reg)
	{
		end_region = ADD(reg, *(size_t*)ADD(reg, 3 * sizeof(void*)));
		ft_putptr(reg);
		ft_putstr("\n");
		ptr = ADD(reg, sizeof(t_reg));
		while (ptr < end_region)
		{
			block_size = *(size_t*)ptr;
			end_block = *(size_t*)ADD(ptr, block_size - sizeof(size_t));
			if (end_block == 0)
				printallocatedblock(ptr);
			ptr = ADD(ptr, block_size);
		}
		ft_putstr("\n\t");
		reg = reg->n;
	}
}
