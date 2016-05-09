/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdlst_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:49:03 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/16 09:47:38 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_putf.h"

void	ft_putdlst_fd(int fd, t_dlist *head, void (*print)(t_dlist *, int)
			, char *sep)
{
	t_dlist		*tmp;

	ft_putf_fd(fd, "HEAD%s", sep);
	tmp = head->next;
	while (tmp != head)
	{
		print(tmp, fd);
		ft_putf_fd(fd, sep);
		tmp = tmp->next;
	}
	ft_putf_fd(fd, "HEAD\n");
	return ;
}
