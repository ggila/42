/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 03:32:11 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		ft_end_power(char *str, int i)
{
	i--;
	while (!ft_strchr("+=-0123456789", str[i]) && str[i] != g_x)
		i--;
	if (ft_strchr("+=-0123456789", str[i]))
		return (0);
	else
		return (1);
}

int		ft_skip_digit(char *str, int i)
{
	int j;

	j = 0;
	while (str[i + j] && ft_strchr("0123456789.,", (str[i + j])))
		j++;
	return (j);
}

int		ft_skip_monom(char *str, int i)
{
	int j;

	j = 0;
	while (str[i + j] && !ft_strchr("-+=", str[i + j]))
		j++;
	return (j);
}

char	ft_isseparator(char *str, int i)
{
	if (ft_strchr(SEPARATOR, str[i]))
		return (1);
	else if (i > 0 && str[i] == '-' && str[i - 1] == ' ')
		return (1);
	return (0);
}

int		ft_skip_space(char *str, int i)
{
	int j;

	j = 0;
	while (str[i + j] && ft_isspace(str[i + j]))
		j++;
	return (j);
}
