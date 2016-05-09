/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hlst_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 15:07:07 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 13:17:33 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hlist.h"

int				ft_hlst_len(t_hlist *head)
{
	int			i;
	t_hlist		*tmp;

	i = 0;
	tmp = head->next;
	while (tmp != head)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
