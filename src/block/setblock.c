/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setblock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 18:37:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/29 03:02:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**                            |_          __________________
**               ptr  ---->   |_         /____block_size____\
**      setblock(ptr) ---->   |_         |                  |
**                            |_         |                  |      ALLOCATED
**                            |_         |                  |
**                            |_         |__________________|
**                            |_         \_______zero_______/
** ptr + block_size   ---->
*/

#include <stdio.h>

void	*setblock(void *ptr, size_t block_size)
{
	void	*last_block;

	*(size_t*)ptr = block_size;
	last_block = (void*)((char*)ptr + block_size - sizeof(size_t));
	*(size_t*)last_block = 0;
	return (ptr + sizeof(size_t));
}
