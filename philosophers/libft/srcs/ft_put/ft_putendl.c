/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:31:17 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/06 19:49:46 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
	return ;
}
