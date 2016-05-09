/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:47:13 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/11 11:17:01 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"
#include "ft_misc.h"

int			ft_atoi(const char *str)
{
	int		sign;
	int		res;

	if (!*str)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += (*(str++) - '0');
	}
	return (res * sign);
}
