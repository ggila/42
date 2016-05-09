/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:37:51 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 18:59:19 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"

int		ft_string_clear(t_string *s)
{
	if (!s)
		return (-1);
	ft_bzero(s->str, s->capacity);
	s->len = 0;
	return (0);
}
