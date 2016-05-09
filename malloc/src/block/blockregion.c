/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noblock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 11:25:21 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/01 19:07:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_glob	g_all;

static int		checkregion(void *ptr, t_reg *reg, void *end)
{
	void	*p;

	p = ADD(reg, sizeof(t_reg) + sizeof(size_t));
	while ((void*)p < end)
	{
		if (p == ptr)
			return (1);
		p = ADD(p, *((size_t*)p - 1));
	}
	return (0);
}

static t_reg	*inregions(void *ptr, t_reg *regs)
{
	t_reg	*reg;
	void	*end;

	reg = regs;
	while (reg)
	{
		end = ADD(reg, reg->size);
		if ((void*)reg < ptr && ptr < end)
		{
			if (checkregion(ptr, reg, end))
				return (reg);
		}
		reg = reg->n;
	}
	return ((t_reg*)NULL);
}

static t_reg	*checkregions(void *ptr, t_reg *regs)
{
	t_reg	*reg;

	if (regs && (reg = inregions(ptr, regs)))
		return (reg);
	return (NULL);
}

t_reg			*blockregion(void *ptr, t_reg ***regs)
{
	t_reg	*reg;

	*regs = &(g_all.tiny);
	if ((reg = checkregions(ptr, g_all.tiny)))
		return (reg);
	*regs = &(g_all.small);
	if ((reg = checkregions(ptr, g_all.small)))
		return (reg);
	*regs = &(g_all.large);
	if ((reg = checkregions(ptr, g_all.large)))
		return (reg);
	return (NULL);
}
