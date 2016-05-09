/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 20:00:12 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 22:30:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_quit(t_dir tab_dir[], int ac)
{
	int i;
	int j;

	i = 0;
	while (i < ac)
	{
		if ((tab_dir[i]).dir)
		{
			j = 0;
			while ((tab_dir[i].files)[j])
			{
				free((tab_dir[i].files)[j]);
				j++;
			}
		}
		free((tab_dir[i]).files);
		free((tab_dir[i]).dir);
		i++;
	}
	return (1);
}

int			ft_tab_init(t_dir tab_dir[], int ac, int not_dir)
{
	int		i;
	int		j;

	i = -1;
	while (++i <= ac)
	{
		tab_dir[i].dir = NULL;
		tab_dir[i].files = NULL;
	}
	i = -1;
	if ((j = not_dir))
	{
		if (!(tab_dir[++i].files = (char**)malloc(sizeof(char*) * (j + 1))))
			return (0);
		tab_dir[i].files[j] = NULL;
		while (j--)
			tab_dir[i].files[j] = NULL;
	}
	while (++i <= ac)
	{
		if (!(tab_dir[i].files = (char**)malloc(sizeof(char*))))
			return (0);
		*(tab_dir[i].files) = NULL;
	}
	return (1);
}

static int	ft_set_tab_file(t_dir tab_dir[], char **av, int not_dir, int c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < not_dir)
	{
		if (av[j][0] && !ft_is_dir(NULL, av[j], ft_strlen(av[j]), c))
		{
			if (!(tab_dir[0].files[i] = ft_strdup(av[j])))
				return (0);
			k = 1;
			i++;
		}
		j++;
	}
	return (k);
}

int			ft_set_tab(int *ac, char **av, t_dir tab_dir[], char c)
{
	int		k;
	int		not_dir;

	if (!ft_tab_init(tab_dir, *ac, not_dir = ft_check_av(av, ac)))
		return (0);
	k = ft_set_tab_file(tab_dir, av, not_dir, c);
	while (k < *ac)
	{
		if (**av)
		{
			if (ft_is_dir(NULL, *av, ft_strlen(*av), c))
			{
				if (!(tab_dir[k].dir = ft_strdup(*av))
						|| !ft_get_dir(&(tab_dir[k])))
					return (0);
				k++;
			}
		}
		else
			(*ac)--;
		av++;
	}
	ft_check_flag(tab_dir, *ac);
	return (1);
}
