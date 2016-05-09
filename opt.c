/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 02:09:04 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 20:34:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_rec(char *path, char *file, int size, char c)
{
	char	pathfile[2 + size];
	t_dir	dir;

	if (ft_strequ(file, ".") || ft_strequ(file, ".."))
		return (1);
	pathfile[0] = '\0';
	ft_strcat(pathfile, path);
	ft_strcat(pathfile, "/");
	ft_strcat(pathfile, file);
	dir.dir = NULL;
	if (!(dir.files = (char**)malloc(sizeof(char*))))
		return (0);
	*dir.files = NULL;
	if (!(dir.dir = ft_strdup(pathfile)) || !ft_get_dir(&dir))
		return (0);
	ft_display(dir, c);
	free(dir.dir);
	while (*dir.files)
	{
		free(*dir.files);
		dir.files++;
	}
	return (1);
}

void	ft_print_un_init(char **files, int *i, int *len, int *n)
{
	*len = ft_strstrlen(files);
	*i = 0;
	*n = g_flag.term_size + 1;
}

void	ft_print_un(char *dir, char **files)
{
	int i;
	int len;
	int n;

	ft_print_un_init(files, &i, &len, &n);
	if (g_flag.long_format)
		ft_print_lf(dir, files);
	else
	{
		while (files[i])
		{
			n -= ft_strlen(files[i]) + 2;
			ft_putstr(files[i++]);
			if (i != len && (n > 2 + ft_strlen(files[i])))
				ft_putstr(g_flag.m ? ", " : "\n");
			else
			{
				n = g_flag.term_size + 1;
				ft_putstr("\n");
			}
		}
		if (i > 0)
			g_flag.has_print = 1;
	}
}

void	ft_set_content(char **files, char *cp_files[])
{
	int i;

	i = -1;
	while (++i < ft_strstrlen(files) + 1)
		cp_files[i] = NULL;
	i = 0;
	while (*files)
	{
		if (g_flag.dot_file || (!g_flag.dot_file && **files != '.'))
		{
			cp_files[i] = *files;
			i++;
		}
		files++;
	}
}
