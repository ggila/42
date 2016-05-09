/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 16:32:29 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/01 19:31:29 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_glob			g_all = {NULL, NULL, NULL};

static t_reg	**getregion(size_t size)
{
	t_reg	**region;

	if (size >= SMALL)
		region = &(g_all.large);
	else
		region = size < TINY ? &(g_all.tiny) : &(g_all.small);
	return (region);
}

static int		getsize(size_t n)
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

void			*malloc(size_t size)
{
	void	*ptr;
	t_reg	**region;

	if (!(size = getsize(size)))
		return (NULL);
	region = getregion(size);
	if (size >= SMALL || *region == NULL
			|| !(ptr = fromregions(*region, size)))
		ptr = fromnewregion(region, size);
	return (ptr);
}
