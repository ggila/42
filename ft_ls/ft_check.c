/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 21:27:22 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 20:12:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_check_flag(t_dir tab_dir[], int ac)
{
	int dir;
	int i;

	dir = 0;
	i = -1;
	while (++i < ac)
	{
		if (tab_dir[i].dir)
			dir++;
	}
	if (dir > 1)
		g_flag.print_dir = 1;
}

int		ft_check_av(char **av, int *ac)
{
	int	cpac;
	int	not_dir;
	int	flag;
	int	i;

	not_dir = 0;
	flag = -1;
	cpac = *ac;
	i = -1;
	while (++i < cpac)
	{
		if (av[i][0] && !ft_is_dir(NULL, av[i], ft_strlen(av[i]), 'm'))
		{
			if (++flag)
				(*ac)--;
			not_dir++;
		}
	}
	return (not_dir);
}

int		ft_check_error(int ac, char **av)
{
	struct stat	buf;
	int			i;

	i = -1;
	while (++i < ac)
	{
		if (lstat(av[i], &buf) == -1)
		{
			ft_putstr_fd("ft_ls: ", STDERR_FILENO);
			perror(av[i]);
			g_flag.print_dir = 1;
			av[i][0] = '\0';
		}
	}
	return (ac);
}

void	ft_check_longest(char **files)
{
	g_flag.longest = 0;
	while (*files)
	{
		if (g_flag.longest < ft_strlen(*files))
			g_flag.longest = ft_strlen(*files);
		files++;
	}
}
