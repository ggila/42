/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 10:47:07 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 01:55:13 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

int				ft_dlst_len(t_dlist *head)
{
	int		i;
	t_dlist	*tmp;

	i = 0;
	tmp = head->next;
	while (tmp != head)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
