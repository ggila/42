/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_move_tail.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 13:03:32 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 01:55:20 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void			ft_dlst_move_tail(t_dlist *list, t_dlist *head)
{
	ft_dlst_del(list);
	ft_dlst_add_tail(list, head);
}
