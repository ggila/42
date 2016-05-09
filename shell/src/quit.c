/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 08:26:49 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_error(char *str)
{
	SET_WHITE;
	ft_putendl(str);
	ft_restore_term();
	exit(1);
}

void	ft_free(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_freefree(char ***ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		ft_free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_restore_term(void)
{
	char	*res;
	char	*area;
	char	buf[20];

	area = buf;
	res = tgetstr("ei", &area);
	tputs(res, 1, ft_putchar_tputs);
	tcsetattr(0, TCSANOW, &g_term_init);
}

void	ft_quit_ok(void)
{
	char				buf[40];
	char				*area;
	char				*res;

	SET_WHITE;
	ft_free(g_env);
	ft_free_hist();
	ft_restore_term();
	ft_putendl("    bye\n");
	area = buf;
	res = tgetstr("bl", &area);
	tputs(res, 1, ft_putchar_tputs);
	res = tgetstr("bl", &area);
	tputs(res, 1, ft_putchar_tputs);
	res = tgetstr("ve", &area);
	tputs(res, 1, ft_putchar_tputs);
	exit(0);
}
