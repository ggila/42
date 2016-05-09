/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:34:14 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 20:01:14 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"

void	ft_string_del(t_string **str_ptr)
{
	t_string	*str;

	if (!str_ptr || !*str_ptr)
		return ;
	str = *str_ptr;
	free(str->str);
	free(str);
	*str_ptr = 0;
}
