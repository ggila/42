/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:29:44 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/05 12:58:50 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strnew(size_t size)
{
	char	*dst;

	if (!(dst = FT_MALLOC(char, size + 1)))
		return (NULL);
	ft_bzero(dst, size + 1);
	return (dst);
}
