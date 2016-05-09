/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 16:44:38 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 22:10:48 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tab.h"
#include "ft_str.h"
#include "ft_mem.h"

void	ft_tabdel(char ***tab_ptr)
{
	size_t	i;

	if (!tab_ptr || !*tab_ptr)
		return ;
	i = 0;
	while ((*tab_ptr)[i])
		ft_strdel(*tab_ptr + i++);
	ft_memdel((void**)tab_ptr);
}
