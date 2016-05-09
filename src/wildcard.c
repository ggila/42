/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 08:51:16 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	ft_fill_fit2(char **fit, char *dir, char *file, char *input)
{
	int				i;
	DIR				*dire;
	struct dirent	*name;

	i = 0;
	if (!(dire = opendir(dir)))
		return ;
	while ((name = readdir(dire)))
	{
		if ((!file || ft_strnequ(name->d_name, file, ft_strlen(file))) &&
			(!ft_strequ(name->d_name, ".") && !ft_strequ(name->d_name, "..")) &&
			((file && file[0] == '.') || name->d_name[0] != '.'))
		{
			if (!(fit[i] = ft_strjoin(input, name->d_name)))
				ft_error("error in malloc (ft_fill_fit)");
			i++;
		}
	}
	closedir(dire);
}

static void	ft_insert_fit(char ***cmd, int i, int count, char **path)
{
	char	**new;
	int		j;

	j = ft_strstrlen((*cmd)) + count + 1;
	if (!(new = (char**)malloc(sizeof(char*) * j)))
		ft_error("malloc failed (ft_insert_fit)");
	ft_memclr(new, j * sizeof(char*));
	j = -1;
	while (++j < i)
	{
		if (!(new[j] = ft_strdup((*cmd)[j])))
			ft_error("ft_strdup failed (ft_insert_fit)");
	}
	ft_fill_fit2(new + j, path[DI], path[FIL], (*cmd)[i]);
	while (new[j])
		j++;
	i++;
	while ((*cmd)[i])
	{
		if (!(new[j++] = ft_strdup((*cmd)[i++])))
			ft_error("ft_strdup failed (ft_insert_fit)");
	}
	ft_free(*cmd);
	*cmd = new;
	free(path);
}

static void	ft_check_fit(char ***cmd, int i)
{
	int			last_char;
	char		**path;
	struct stat	buf;
	int			count;

	last_char = ft_strlen((*cmd)[i]) - 1;
	(*cmd)[i][last_char] = '\0';
	path = ft_get_path((*cmd)[i]);
	lstat(path[DI], &buf);
	if ((buf.st_mode & S_IFMT) != S_IFDIR)
		return ;
	count = ft_count(path[DI], path[FIL]);
	if (count)
		ft_insert_fit(cmd, i, count, path);
	else
	{
		free(path);
		(*cmd)[i][last_char] = '*';
	}
}

void		ft_wildcard_explode(char ***cmd)
{
	int i;

	i = 0;
	while ((*cmd)[i])
	{
		if ((*cmd)[i][ft_strlen((*cmd)[i]) - 1] == '*')
			ft_check_fit(cmd, i);
		i++;
	}
}
