/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 04:54:46 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 22:44:58 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_time_sort(t_dir dir, t_key_sort tab[], int len, char c)
{
	int			i;
	char		*str;
	struct stat	buf;

	i = -1;
	while (++i < len)
	{
		if (!(str = ft_make_path(dir.dir, dir.files[i])))
			return (0);
		(void)c;
		lstat(str, &buf);
		tab[i].key.time = g_flag.t ? buf.st_mtimespec.tv_sec :
			buf.st_atimespec.tv_sec;
		free(str);
	}
	return (1);
}

int		ft_ll_sort(t_dir dir, t_key_sort tab[], int len, char c)
{
	int			i;
	char		*str;
	struct stat	buf;

	i = -1;
	while (++i < len)
	{
		if (!(str = ft_make_path(dir.dir, dir.files[i])))
			return (0);
		if (!ft_get_stat(str, &buf, c))
		{
			free(str);
			ft_putendl(str);
			return (0);
		}
		tab[i].key.ent = (buf.st_mode & S_IFMT) == S_IFDIR;
		free(str);
	}
	return (1);
}

int		ft_size_sort(t_dir dir, t_key_sort tab[], int len, char c)
{
	int			i;
	char		*str;
	struct stat	buf;

	i = -1;
	while (++i < len)
	{
		if (!(str = ft_make_path(dir.dir, dir.files[i])))
			return (0);
		if (!ft_get_stat(str, &buf, c))
		{
			free(str);
			ft_putendl(str);
			return (0);
		}
		tab[i].key.ent = buf.st_size;
		free(str);
	}
	return (1);
}

void	ft_sort_key(t_dir dir, int len, char c, char k)
{
	t_key_sort	tab[len];

	ft_set_key_sort(dir.files, tab, '>');
	if (k == 't')
	{
		if (!ft_time_sort(dir, tab, len, c))
			return ;
		ft_my_sort((void*)tab, ft_cmp_time, sizeof(t_key_sort), len - 1);
	}
	else if (k == 'S')
	{
		if (!ft_size_sort(dir, tab, len, c))
			return ;
		ft_my_sort((void*)tab, ft_cmp_int, sizeof(t_key_sort), len - 1);
	}
	else if (k == 'l')
	{
		if (!ft_ll_sort(dir, tab, len, c))
			return ;
		ft_my_sort((void*)tab, ft_cmp_int, sizeof(t_key_sort), len - 1);
	}
	ft_set_key_sort(dir.files, tab, '<');
}

int		ft_my_sort_opt(t_dir dir, int len, char c)
{
	if (g_flag.t || g_flag.u)
		ft_sort_key(dir, len, c, 't');
	if (g_flag.size)
		ft_sort_key(dir, len, c, 'S');
	if (g_flag.ll)
		ft_sort_key(dir, len, c, 'l');
	else if (!g_flag.size && !g_flag.t && !g_flag.u)
		ft_my_sort((void*)dir.files, ft_cmp_opt, sizeof(char*), len - 1);
	return (1);
}
