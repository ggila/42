/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 16:44:16 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/06 22:31:03 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

void	ft_puttab_fd(char **tab, int fd)
{
	if (!tab)
		return ;
	while (*tab)
	{
		ft_putendl_fd(*tab, fd);
		tab++;
	}
	return ;
}
