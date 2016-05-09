/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 19:38:56 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/02 16:12:50 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	freeregion(t_reg *reg, t_reg **regs)
{
	if (reg->p)
		reg->p->n = reg->n;
	else
		*regs = reg->n;
	if (reg->n)
		reg->n->p = reg->p;
	munmap(reg, reg->size);
}

void		free(void *ptr)
{
	t_reg	**regs;
	t_reg	*reg;
	void	*around[2];

	regs = NULL;
	if ((reg = blockregion(ptr, &regs)) == NULL)
		return ;
	checkaroundblock(reg, ptr, around);
	setfreeblock((t_free*)ADD(ptr, -sizeof(size_t)), reg, around);
	if (reg->n && reg->size == reg->free->size + sizeof(t_reg))
		freeregion(reg, regs);
}
