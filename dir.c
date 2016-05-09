/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 22:20:29 by ggilaber          #+#    #+#             */
/*   Updated: 2014/12/21 23:51:25 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_fill_dir(t_dir *dir, DIR *directory)
{
	int				i;
	struct dirent	*diret;

	i = -1;
	while ((diret = readdir(directory)))
	{
		if (directory && !(g_flag.a && (ft_strequ(".", diret->d_name)
						|| ft_strequ("..", diret->d_name))))
		{
			++i;
			if (!(dir->files[i] = ft_strdup(diret->d_name)))
				return (0);
		}
	}
	closedir(directory);
	return (1);
}

int			ft_get_dir(t_dir *dir)
{
	int				count;
	int				cp;
	DIR				*directory;

	directory = NULL;
	count = ft_count(dir->dir);
	cp = count;
	free(dir->files);
	if (!(dir->files = (char**)malloc(sizeof(char*) * (count + 1))))
		return (0);
	while (count >= 0)
		(dir->files)[count--] = NULL;
	directory = opendir(dir->dir);
	if (directory && !ft_fill_dir(dir, directory))
		return (0);
	ft_my_sort((void*)(dir->files), ft_cmp_opt, sizeof(char*), cp - 1);
	return (1);
}

int			ft_get_stat(char *str, struct stat *buf, char c)
{
	if (c == 'm' && stat(str, buf))
		return (0);
	else if (c != 'm' && lstat(str, buf))
		return (0);
	return (1);
}

int			ft_is_dir(char *dir, char *file, int size, char c)
{
	struct stat	buf;
	char		pathfile[2 + size];
	int			i;

	i = -1;
	while (++i < 2 + size)
		pathfile[i] = '\0';
	if (c == 'm')
		ft_strcat(pathfile, file);
	else
	{
		ft_strcat(pathfile, dir);
		ft_strcat(pathfile, "/");
		ft_strcat(pathfile, file);
	}
	ft_get_stat(pathfile, &buf, c);
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	else
		return (0);
}
