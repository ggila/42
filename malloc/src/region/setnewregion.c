/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnewregion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 18:53:47 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/30 18:24:16 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**                      ____   _          __________________
**       new_reg  -->  |      |_         /     previous     \      REGION HEADER
**                     |      |_         |       next       |
**                     |      |_         |       free       |
**                     |      |_         \_____reg_size_____/
**                     |      |_         /____block_size____\
**                     |      |_         |                  |
**                     |      |_         |                  |      ALLOCATED
**                     |      |_         |                  |
**                     |      |_         |__________________|
**                     |____  |_         \_______zero_______/
**                     |      |_         /    block_size    \
**                     |      |_         |     previous     |
**               page  |      |_         |_______next_______|
**                     |      |_         |                  |        FREE
**                     |      |_         |                  |
**                    ...    ...         |                  |
**                     |      |_         |                  |
**                     |      |_         |                  |
**                     |      |_         |__________________|
**                     |____  |_         \____block_size____/
**new_reg + reg_size ->|      |_
**                     |      |_
*/

static void	setll(t_reg **reg, t_reg *new_reg)
{
	t_reg	*tmp;

	if (*reg == NULL)
	{
		*reg = new_reg;
		(*reg)->p = NULL;
		(*reg)->n = NULL;
	}
	else
	{
		tmp = *reg;
		while (tmp->n)
			tmp = tmp->n;
		tmp->n = new_reg;
		new_reg->p = tmp;
		new_reg->n = NULL;
	}
}

static void	setregionheader(t_reg *new_reg, t_reg **reg,
		size_t reg_size, size_t block_size)
{
	setll(reg, new_reg);
	new_reg->free = (t_free*)((char*)new_reg
			+ sizeof(t_reg) + block_size);
	new_reg->size = reg_size;
}

static void	setfreezone(t_free *free, t_reg *new_reg,
		size_t reg_size, size_t block_size)
{
	free->size = (size_t)(reg_size - sizeof(t_reg) - block_size);
	free->p = NULL;
	free->n = NULL;
	*(size_t*)((char*)new_reg + reg_size - sizeof(size_t)) = free->size;
}

void		setnewregion(t_reg *new_reg, t_reg **reg,
				size_t block_size, size_t reg_size)
{
	setregionheader(new_reg, reg, reg_size, block_size);
	setblock((void*)(new_reg + 1), block_size);
	setfreezone(new_reg->free, new_reg, reg_size, block_size);
}
