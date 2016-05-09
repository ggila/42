/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 03:38:29 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static double	ft_get_dec(char *str, int i)
{
	int		j;
	double	dec;
	double	ret;

	j = 1;
	dec = 1;
	ret = 0;
	while (ft_strchr("0123456789", str[i + j]))
	{
		dec *= 0.1;
		ret += dec * (double)(str[i + j] - '0');
		j++;
	}
	return (ret);
}

double			ft_get_number(char *str, int i)
{
	double	ret;
	double	d;
	int		n;

	n = -1;
	d = 0;
	if (ft_strchr("0123456789", str[i]))
		n = ft_atoi(str + i);
	while (ft_strchr("0123456789", str[i]))
		i++;
	if (ft_strchr(",.", str[i]))
		d = ft_get_dec(str, i);
	if (n == -1)
		ret = d >= 0 ? d : 1;
	else
		ret = n + d;
	return (ret);
}
