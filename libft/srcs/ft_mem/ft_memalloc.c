/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:14:02 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 21:49:38 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memalloc(size_t size)
{
	void	*dst;

	if (!(dst = (void *)malloc(size)))
		return (NULL);
	ft_bzero(dst, size);
	return (dst);
}
