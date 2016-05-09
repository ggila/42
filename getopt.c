/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 16:05:56 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 23:48:20 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_set_flag(void)
{
	struct winsize w;

	if (g_flag.f)
		g_flag.dot_file = 1;
	if (!g_flag.un || g_flag.m)
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		g_flag.term_size = w.ws_col;
	}
	if (g_flag.dot_file && g_flag.a)
		g_flag.a = 0;
	else if (!g_flag.dot_file && g_flag.a)
		g_flag.dot_file = 1;
	else if (g_flag.u && g_flag.t)
		g_flag.t = 0;
	if (g_flag.long_format)
	{
		if (g_flag.long_format == 2)
			g_flag.ll = 1;
	}
	return (1);
}

static void		ft_set_opt(char c)
{
	if (c == 'a')
		g_flag.dot_file = 1;
	else if (c == 'R')
		g_flag.recursive = 1;
	else if (c == 'r')
		g_flag.reverse = 1;
	else if (c == 't')
		g_flag.t = 1;
	else if (c == 'u')
		g_flag.u = 1;
	else if (c == 'A')
		g_flag.a = 1;
	else if (c == 'S')
		g_flag.size = 1;
	else if (c == 'f')
		g_flag.f = 1;
	else if (c == 'm')
		g_flag.m = 1;
	ft_set_lopt(c);
	return ;
}

static void		ft_flag_init(void)
{
	g_flag.term_size = 0;
	g_flag.longest = 0;
	g_flag.long_format = 0;
	g_flag.dot_file = 0;
	g_flag.recursive = 0;
	g_flag.reverse = 0;
	g_flag.t = 0;
	g_flag.u = 0;
	g_flag.has_print = 0;
	g_flag.print_dir = 0;
	g_flag.a = 0;
	g_flag.un = 0;
	g_flag.ll = 0;
	g_flag.size = 0;
	g_flag.m = 0;
}

static int		ft_check_opt(int *ac, char ***av)
{
	if (!(***av))
	{
		(*ac)++;
		(**av)--;
		return (STOP);
	}
	if (***av == '-')
	{
		if (*(**av + 1))
			return (FAIL);
		(*av)++;
		return (STOP);
	}
	while (***av)
	{
		if (ft_strchr("ARSaflmrtu1", ***av))
			ft_set_opt(***av);
		else
			return (FAIL);
		(**av)++;
	}
	(*av)++;
	return (OK);
}

int				ft_get_opt(int *ac, char ***av)
{
	int			i;
	int			n;

	(*ac)--;
	(*av)++;
	ft_flag_init();
	i = -1;
	while (*ac && (++i <= *ac) && ***av == '-')
	{
		(*ac)--;
		(**av)++;
		if ((n = ft_check_opt(ac, av)) == FAIL)
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(***av);
			ft_putchar('\n');
			ft_putendl("usage: ft_ls [-ARSaflmrtu1] [file ...]");
			return (0);
		}
		else if (n == STOP)
			return (ft_set_flag());
	}
	return (ft_set_flag());
}
