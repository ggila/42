/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_prev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 13:02:47 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/12 23:03:07 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist			*ft_dlst_prev(t_dlist *list, t_dlist *head)
{
	if (ft_dlst_is_singular(head))
		return (list);
	if (list->prev == head)
		return (head->prev);
	return (list->prev);
}
