/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 17:25:16 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/01 19:10:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int	getsize(size_t n)
{
	size_t	min_size;

	if (n > 0)
	{
		n = sizeof(size_t) * ((n - 1) / sizeof(size_t) + 1);
		min_size = 2 * sizeof(void*);
		return (n < min_size ? min_size : n);
	}
	return (0);
}

static int	checknext(void *ptr, size_t size, t_reg *reg)
{
	void	*next;

	ptr = ADD(ptr, -sizeof(size_t));
	next = ADD(ptr, *(size_t*)ptr);
	if (next > ADD(reg, reg->size) || LAST_SIZE(next) == 0)
		return (0);
	if (SIZE(ptr) + SIZE(next) - 2 * sizeof(size_t) >= size)
		return (1);
	return (0);
}

void		*realloc(void *ptr, size_t size)
{
	t_reg	**regs;
	t_reg	*reg;
	void	*new_ptr;

	size = getsize(size);
	if (!ptr)
		return (malloc(size));
	else if (!(reg = blockregion(ptr, &regs)))
		return (NULL);
	else if (size + 2 * sizeof(size_t) <= *((size_t*)ptr - 1))
		return (ptr);
	else if (checknext(ptr, size, reg))
	{
		enlargeblock(ptr, size, reg);
		return (ptr);
	}
	else
	{
		new_ptr = malloc(size);
		ft_memcpy(new_ptr, ptr,
				*(size_t*)(ptr - sizeof(size_t)) - 2 * sizeof(size_t));
		free(ptr);
		return (new_ptr);
	}
	return (NULL);
}
