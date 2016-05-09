/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:55:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/08/24 19:17:19 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_list(t_list *list)
{
	while (list->next)
	{
		ft_putchar(*(char const*)(list->content));
		ft_putstr("->");
		list = list->next;
	}
	ft_putchar(*(char const*)list->content);
	ft_putchar('\n');
}
