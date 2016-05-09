/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkaroundblock.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 13:54:20 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/30 18:21:45 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	checkbefore(t_reg *reg, void *ptr, void *around[2])
{
	size_t	prev;

	prev = *((size_t*)ptr - 2);
	if (ADD(reg, sizeof(t_reg) + sizeof(size_t)) == ptr || prev == 0)
		around[0] = NULL;
	else
		around[0] = ADD(ptr, -prev - sizeof(size_t));
}

void	checkafter(t_reg *reg, void *ptr, void *around[2])
{
	void	*next;

	next = ADD(ptr, *((size_t*)ptr - 1) - sizeof(size_t));
	if (next >= ADD(reg, reg->size)
			|| *(size_t*)ADD(next, *(size_t*)next - sizeof(size_t)) == 0)
		around[1] = NULL;
	else
		around[1] = next;
}

void	checkaroundblock(t_reg *reg, void *ptr, void *around[2])
{
	checkbefore(reg, ptr, around);
	checkafter(reg, ptr, around);
}
