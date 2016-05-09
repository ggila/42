/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:30:02 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/10 18:34:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void ft_lstpush(t_list *alst, t_list *new)
{
	if (!alst || !new)
		return ;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
}
