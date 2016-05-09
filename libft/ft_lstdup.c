/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:18:02 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/11 12:01:50 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstdup(t_list *todup)
{
	t_list *list;

	if (!todup)
		return (NULL);
	list = ft_lstnew(todup->content, todup->content_size);
	todup = todup->next;
	while (todup)
	{
		ft_lstpush(list, ft_lstnew(todup->content, todup->content_size));
		todup = todup->next;
	}
	return (list);
}