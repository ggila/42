/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:55:39 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/29 11:39:16 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int			ft_string_add(t_string *dst, char c)
{
	if (!dst || ft_string_resize(dst, dst->len + 1) < 0)
		return (-1);
	dst->str[dst->len++] = c;
	dst->str[dst->len] = 0;
	return (0);
}
