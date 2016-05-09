/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 03:09:30 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	ft_check_end(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		i--;
	if (!ft_strchr("0123456789x", str[i]))
		ft_quit("wrong end", NULL, 0, i);
}

void	ft_check_nb_equal(char *str)
{
	int		i;
	char	flag;

	flag = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '=')
			flag++;
	if (flag > 1)
		ft_quit("too many '=', need 'lhs = rhs'", NULL, 0, -1);
}

void	ft_check_eq(char *str)
{
	int		i;

	i = 0;
	ft_check_nb_equal(str);
	i += ft_skip_space(str, i);
	if (str[i++] == '=')
		ft_quit("no lhs, need 'lhs = rhs'", NULL, 0, -1);
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i++])
		ft_quit("no '=', need 'lhs = rhs'", NULL, 0, -1);
	i += ft_skip_space(str, i);
	if (!str[i])
		ft_quit("no rhs, need 'lhs = rhs'", NULL, 0, -1);
}

void	ft_check_x(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_strchr(LEGAL, str[i]))
		++i;
	if (!str[i])
		ft_quit("x is missing, need unknown data", LEGAL, 0, -1);
	g_x = str[i];
	++i;
	while (str[i] && (ft_strchr(LEGAL_ERROR, str[i]) || str[i] == g_x))
		++i;
	if (str[i])
		ft_quit("unexpected char", LEGAL_ERROR, str[i], i);
}
