/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnewregion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 09:48:45 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/02 17:55:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**          _      _          __________________
**         |      |_         /     previous     \      REGION HEADER
**         |      |_         |       next       |
**         |      |_         |       free       |
**         |      |_         \_____reg_size_____/
**         |      |_         /____block_size____\
**         |      |_         |                  |
**         |      |_         |                  |      ALLOCATED
**    page |      |_         |                  |
**         |      |_         |__________________|
**         |      |_         \_______zero_______/
**         |_     |_         /     previous     \
**         |      |_         |       next       |
**         |      |_         |____block_size____|        FREE
**         |      |_         |                  |
**         |      |_         |                  |
**        ...     ...                ...
**         |      |_         |                  |
**         |      |_         |                  |
**         |      |_         |                  |
**         |      |_         |__________________|
**         |_     |_         \____block_size____/
*/

static size_t	getregsize(size_t size)
{
	size_t pagesize;

	if (size < SMALL)
		size = 100 * ((size < TINY ? TINY : SMALL) + 2 * sizeof(size_t));
	else
		size += 2 * sizeof(size_t);
	pagesize = getpagesize();
	return (pagesize * (size / pagesize + 1));
}

static void		*getnewregion(size_t reg_size)
{
	void	*ptr;

	ptr = mmap(0, reg_size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	return ((t_reg*)ptr);
}

void			*fromnewregion(t_reg **reg, size_t size)
{
	size_t	reg_size;
	size_t	block_size;
	t_reg	*new_region;
	void	*ptr;

	reg_size = getregsize(size);
	new_region = getnewregion(reg_size);
	block_size = size + 2 * sizeof(size_t);
	setnewregion(new_region, reg, block_size, reg_size);
	ptr = (void*)((char *)new_region + sizeof(t_reg) + sizeof(size_t));
	return (ptr);
}
