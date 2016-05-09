/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enlargeblock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 16:08:05 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/01 17:21:24 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	limitcase(void *ptr, size_t size, t_free old, t_reg *reg)
{
	if (old.p)
		old.p->n = old.n;
	else
		reg->free = old.n;
	if (old.n)
		old.n->p = old.p;
	setblock(ptr, size);
}

static void	normalcase(void *ptr, size_t size, t_free old, t_reg *reg)
{
	t_free	*free;
	size_t	old_block_size;

	old_block_size = SIZE(ptr);
	SIZE(ptr) = size;
	LAST_SIZE(ptr) = 0;
	free = (t_free*)ADD(ptr, size);
	if (old.p)
		old.p->n = free;
	else
		reg->free = free;
	if (old.n)
		old.n->p = free;
	free->size = old.size - (size - old_block_size);
	LAST_SIZE(free) = size;
}

void		enlargeblock(void *ptr, size_t size, t_reg *reg)
{
	t_free	old;
	size_t	old_block_size;

	ptr = ADD(ptr, -sizeof(size_t));
	old_block_size = SIZE(ptr);
	old = *(t_free*)NEXT(ptr);
	if (old.size + old_block_size - size
			< 2 * (sizeof(void*) + sizeof(size_t)))
		limitcase(ptr, old.size + old_block_size, old, reg);
	else
		normalcase(ptr, size, old, reg);
}
