/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 03:00:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static int	ft_check_digit(char *str, int i)
{
	int j;

	if (str[i] && !ft_strchr("0123456789,.", str[i]))
		ft_quit(DIGIT_ERROR_1, NULL, 0, i);
	j = 0;
	while (str[i + j] && ft_strchr("0123456789", str[i + j]))
		j++;
	if (str[i + j] == '.' || str[i + j] == ',')
	{
		j++;
		while (str[i + j] && ft_strchr("0123456789", str[i + j]))
			j++;
		if (str[i + j] == '.' || str[i + j] == ',')
			ft_quit(DIGIT_ERROR_2, NULL, 0, i + j);
	}
	return (j);
}

static int	ft_check_power(char *str, int i)
{
	int j;

	j = 1;
	j += ft_skip_space(str, i + j);
	if (str[i + j] == '^')
	{
		j += 1 + ft_skip_space(str, i + j + 1);
		if (str[i + j] && (ft_strchr(".,", str[i + j])
		|| ft_atoi(str + i + j) > 3))
			ft_quit("expected integer power smaller than 3", NULL, 0, i + j);
		if (!str[i + j] || !ft_strchr("0123456789", str[i + j]))
			j += ft_check_digit(str, i + j);
		j += ft_check_digit(str, i + j);
		j += ft_skip_space(str, i + j);
	}
	if (ft_strchr("0123456789", str[i + j]))
	{
		if (ft_atoi(str + i + j) > 3)
			ft_quit("expected power smaller than 3", NULL, 0, i + j);
		j += ft_check_digit(str, i + j);
	}
	j += ft_skip_space(str, i + j);
	if (!ft_strchr("+=-", str[i + j]))
		ft_quit("'-', '+' or '=' expected\n", NULL, 0, i);
	return (j);
}

static void	ft_check_monom2(char *str, int *i)
{
	if (str[*i] && str[*i] != g_x && !ft_strchr("-+=", str[*i]))
		ft_quit("x, '-', '+' or '=' expected\n", NULL, 0, *i);
	else if (str[*i] == g_x)
		*i += ft_check_power(str, *i);
	*i += ft_skip_monom(str, *i);
	if (str[*i] == '=')
	{
		(*i)++;
		*i += ft_skip_space(str, *i);
	}
	if (str[*i])
		*i += ft_strchr("+=-", str[*i]) ? 1 : 0;
}

static void	ft_check_monom(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		i += ft_skip_space(str, i);
		if (str[i] && str[i] != g_x)
			i += ft_check_digit(str, i);
		i += ft_skip_space(str, i);
		if (str[i] && str[i] == '*')
		{
			i++;
			i += ft_skip_space(str, i);
			if (str[i] && str[i] != g_x)
				ft_quit("expected x", NULL, 0, i);
		}
		ft_check_monom2(str, &i);
	}
}

void		ft_check_input(char *str)
{
	g_str_init = str;
	ft_check_eq(str);
	ft_check_x(str);
	ft_check_monom(str);
	ft_check_end(str);
}
