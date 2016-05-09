/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:14:13 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 22:02:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_dot_only(t_dir tab_dir[], int *ac)
{
	if (!ft_tab_init(tab_dir, *ac, 0))
		return (0);
	if (!(tab_dir[0].dir = ft_strdup(".")))
		return (0);
	if (!(tab_dir[0].files = (char**)malloc(sizeof(char*))))
		return (0);
	if (!ft_get_dir(tab_dir))
		return (0);
	ft_display(tab_dir[0], 'm');
	free(tab_dir[0].dir);
	free(*(tab_dir[0].files));
	free(tab_dir[0].files);
	return (1);
}

void	ft_display(t_dir dir, char c)
{
	int i;

	if (*dir.files && !ft_my_sort_opt(dir, ft_strstrlen(dir.files), c))
		return ;
	ft_print(dir);
	if (g_flag.recursive)
	{
		g_flag.print_dir = 1;
		i = -1;
		while (dir.files[++i])
			if (ft_is_dir(dir.dir, dir.files[i], ft_strlen(dir.dir)
				+ ft_strlen(dir.files[i]), 'n')
					&& !ft_rec(dir.dir, dir.files[i], ft_strlen(dir.dir)
						+ ft_strlen(dir.files[i]), 'n'))
				return ;
	}
}

int		main(int ac, char **av)
{
	t_dir	tab_dir[ac];
	int		i;

	if (!ft_get_opt(&ac, &av))
		return (1);
	if (!ac && !ft_dot_only(tab_dir, &ac))
		return (1);
	else if (ac)
	{
		if (!g_flag.f)
			ft_my_sort((void*)av, ft_cmp_lex, sizeof(char*), ac - 1);
		if (!(ft_check_error(ac, av)))
			return (1);
		ft_my_sort((void*)av, ft_cmp_file_dir, sizeof(char*), ac - 1);
		if (!(ft_set_tab(&ac, av, tab_dir, 'm')))
			return (ft_quit(tab_dir, ac));
		ft_check_flag(tab_dir, ac);
		i = 0;
		while (i < ac)
			ft_display(tab_dir[i++], 'm');
		ft_quit(tab_dir, ac);
	}
	return (0);
}
