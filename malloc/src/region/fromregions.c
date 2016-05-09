/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fromregion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 17:58:22 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/30 18:23:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	erasefree(t_reg *reg, t_free *free, size_t *blocksize)
{
	*blocksize = free->size;
	if (free->p)
		free->p->n = free->n;
	else
		reg->free = free->n;
	if (free->n)
		free->n->p = free->p;
}

static void	changefreeblock(t_reg *reg, t_free *free, size_t *block_size)
{
	t_free	*new;

	if (free->size - *block_size <= 2 * (sizeof(size_t) + sizeof(void*)))
		erasefree(reg, free, block_size);
	else
	{
		new = (void*)((char*)free + *block_size);
		new->p = free->p;
		new->n = free->n;
		new->size = free->size - *block_size;
		*(size_t*)((char*)new + new->size - sizeof(size_t)) = new->size;
		if (free->p)
			free->p->n = new;
		else
			reg->free = new;
		if (free->n)
			free->n->p = new;
	}
}

void		*fromregions(t_reg *reg, size_t size)
{
	size_t	block_size;
	t_free	*free;
	void	*ptr;

	block_size = size + 2 * sizeof(size_t);
	while (reg)
	{
		free = reg->free;
		while (free && (block_size >= free->size))
			free = free->n;
		if (free)
			break ;
		reg = reg->n;
	}
	if (!free)
		return (NULL);
	changefreeblock(reg, free, &block_size);
	ptr = setblock((void*)free, block_size);
	return (ptr);
}
