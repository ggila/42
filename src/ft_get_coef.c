/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coef.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 18:38:56 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/05 11:23:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static int	ft_check_first_sign(char *str)
{
	if (str[0] == '-')
	{
		g_flag_op |= MASK_MINUS;
		return (1);
	}
	else
		g_flag_op &= ~MASK_MINUS;
	return (0);
}

static void	ft_check_sign(char *str, int *i)
{
	if (str[*i] == '=')
	{
		g_flag_op |= MASK_EQUAL;
		g_flag_op |= MASK_MINUS;
		(*i) += 1;
		*i += ft_skip_space(str, *i);
	}
	if (str[*i] == '-' && g_flag_op & MASK_EQUAL)
		g_flag_op &= ~MASK_MINUS;
	else if (str[*i] == '-' && !(g_flag_op & MASK_EQUAL))
		g_flag_op |= MASK_MINUS;
	else if (str[*i] == '+' && g_flag_op & MASK_EQUAL)
		g_flag_op |= MASK_MINUS;
	else if (str[*i] == '+' && !(g_flag_op & MASK_EQUAL))
		g_flag_op &= ~MASK_MINUS;
	if (ft_strchr("+-", str[*i]))
		*i += 1;
}

static int	ft_get_coef(char *str, int i, double *n1)
{
	int j;

	j = 0;
	while (str[i + j] && !ft_strchr(".,0123456789", str[i + j])
	&& str[i + j] != g_x)
		j++;
	if (str[i + j] && ft_strchr(".,0123456789", str[i + j]))
	{
		*n1 = ft_get_number(str, i + j);
		j += ft_skip_digit(str, i + j);
	}
	else if (str[i + j] == g_x)
		*n1 = 1;
	return (j);
}

static int	ft_get_power(char *str, int i, int *n2)
{
	int j;

	j = 0;
	while (str[i + j] && str[i + j] != g_x && !ft_strchr("+=-", str[i + j]))
		j++;
	if (str[i + j] == g_x)
	{
		while (str[i + j] && !ft_strchr("+=-0123456789", str[i + j]))
			j++;
		if (!str[i + j] || ft_strchr("+=-", str[i + j]))
			*n2 = 1;
		else
			*n2 = ft_get_number(str, i + j);
	}
	else if (!str[i + j] || ft_strchr("+=-", str[i + j]))
		*n2 = 0;
	return (j);
}

void		ft_get_values(char *str)
{
	int		i;
	double	n1;
	int		n2;

	i = 0;
	i += ft_check_first_sign(str);
	while (str[i])
	{
		if (i > 1 && ft_strchr("+=-", str[i]))
			ft_check_sign(str, &i);
		while (str[i] && str[i] != g_x && !ft_strchr(".,0123456789", str[i]))
			i++;
		i += str[i] ? ft_get_coef(str, i, &n1) : 0;
		n1 *= g_flag_op & MASK_MINUS ? -1 : 1;
		while (str[i] && ft_strchr(" \t*", str[i]))
			i++;
		i += str[i] ? ft_get_power(str, i, &n2) : 0;
		g_monom[(str[i] ? n2 : ft_end_power(str, i))] += n1;
		i += str[i] ? ft_skip_monom(str, i) : 0;
	}
}
