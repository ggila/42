/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 21:26:10 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/13 22:01:08 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void ft_putstr_fd(const char *str, int fd)
{
	if (!str)
		return ;
	else
		write(fd, str, ft_strlen(str));
}
