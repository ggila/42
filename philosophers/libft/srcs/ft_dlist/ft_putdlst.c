/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:49:03 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/16 09:46:37 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_putf.h"

void	ft_putdlst(t_dlist *head, void (*print)(t_dlist *), char *sep)
{
	t_dlist		*tmp;

	ft_putf("HEAD%s", sep);
	tmp = head->next;
	while (tmp != head)
	{
		print(tmp);
		ft_putf(sep);
		tmp = tmp->next;
	}
	ft_putf("HEAD\n");
	return ;
}
