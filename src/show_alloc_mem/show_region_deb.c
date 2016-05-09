/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 16:51:53 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/02 17:56:22 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		printfreeblock(void *ptr)
{
	size_t	size;

	SET_GREEN;
	size = *(size_t*)ptr;
	ft_putstr("____________________\n");
	ft_printnbr(ptr, *(size_t*)ptr);
	ptr = ADD(ptr, sizeof(size_t));
	ft_printptr(ptr, *((void**)ptr));
	ptr = ADD(ptr, sizeof(void*));
	ft_printptr(ptr, *((void**)ptr));
	ft_putstr("\t|   ...\n");
	ptr = ADD(ptr, size - 2 * sizeof(size_t) - sizeof(void*));
	ft_printnbr(ptr, *(size_t*)ptr);
	ft_putstr("\t|___________________");
	SET_WHITE;
}

static void		printallocatedblock(void *ptr)
{
	void	*end;

	SET_RED;
	ft_putstr("____________________\n");
	end = ADD(ptr, *(size_t*)ptr - sizeof(size_t));
	ft_printnbr(ptr, *(size_t*)ptr);
	ft_printarea(ADD(ptr, sizeof(size_t)),
			ADD(end, -1), *(size_t*)ptr - 2 * sizeof(size_t));
	ft_printnbr(end, *(size_t*)end);
	ft_putstr("\t|___________________");
	SET_WHITE;
}

static void		printregionheader(void *ptr)
{
	ft_putstr("____________________\n");
	ft_printptr(ptr, *(void**)ptr);
	ptr = ADD(ptr, sizeof(void*));
	ft_printptr(ptr, *(void**)ptr);
	ptr = ADD(ptr, sizeof(void*));
	ft_printptr(ptr, *(void**)ptr);
	ptr = ADD(ptr, sizeof(void*));
	ft_printnbr(ptr, *(size_t*)ptr);
	ft_putstr("\t|___________________");
}

void			show_region_deb(t_reg *reg)
{
	void	*ptr;
	void	*end_region;
	size_t	block_size;
	size_t	end_block;

	ft_putstr("\n");
	while (reg)
	{
		ft_putstr("\t____________________");
		end_region = ADD(reg, *(size_t*)ADD(reg, 3 * sizeof(void*)));
		printregionheader((void*)reg);
		ptr = ADD(reg, sizeof(t_reg));
		while (ptr < end_region)
		{
			block_size = *(size_t*)ptr;
			end_block = *(size_t*)ADD(ptr, block_size - sizeof(size_t));
			(end_block == 0) ? printallocatedblock(ptr) :
				printfreeblock(ptr);
			ptr = ADD(ptr, block_size);
		}
		ft_putstr("____________________\n");
		reg = reg->n;
	}
}
