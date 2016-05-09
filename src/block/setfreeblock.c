/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 19:38:56 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/30 18:22:10 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	setoneblock(t_free *block, t_reg *reg)
{
	block->n = reg->free;
	block->p = NULL;
	*(size_t*)ADD(block, block->size - sizeof(size_t)) = block->size;
	reg->free->p = block;
	reg->free = block;
}

static void	setblockbefore(t_free *block, t_reg *reg, t_free *merge)
{
	block->size += merge->size;
	if ((block->p = merge->p))
		block->p->n = block;
	else
		reg->free = block;
	if ((block->n = merge->n))
		block->n->p = block;
	*(size_t*)ADD(merge, merge->size - sizeof(size_t)) = block->size;
}

static void	setblockafter(t_free *block, t_free *merge)
{
	merge->size += *(size_t*)block;
	*(size_t*)ADD(block, *(size_t*)block - sizeof(size_t)) = merge->size;
}

void		setfreeblock(t_free *block, t_reg *reg, void *around[2])
{
	if (!around[0] && !around[1])
		setoneblock(block, reg);
	if (around[1])
		setblockbefore(block, reg, around[1]);
	if (around[0])
		setblockafter(block, around[0]);
}
