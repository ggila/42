/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:51:22 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/10 15:47:35 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (!del || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
