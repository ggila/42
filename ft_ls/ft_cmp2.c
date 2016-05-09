/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 22:13:20 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 23:49:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cmp_lex(void *s1, void *s2)
{
	return (ft_strcmp(*(const char**)s1, *(const char**)s2));
}

int		ft_cmp_opt(void *s1, void *s2)
{
	if (g_flag.reverse)
		return (g_flag.f ? 0 : -ft_cmp_lex(s1, s2));
	return (g_flag.f ? 0 : ft_cmp_lex(s1, s2));
}

void	ft_print_init(int *flag, int *n, int *len, int len_while)
{
	*flag = 0;
	*n = 0;
	*len = len_while;
}

void	ft_set_lopt(char c)
{
	if (c == 'l')
	{
		++(g_flag.long_format);
		g_flag.un = 0;
	}
	else if (c == '1')
	{
		g_flag.un = 1;
		g_flag.long_format = 0;
	}
	return ;
}
