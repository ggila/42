/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 19:32:53 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 23:27:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_space(char *temp, int *flag, int *n)
{
	int j;

	*n += 8 * (g_flag.longest / 8 + 1);
	if (g_flag.term_size - *n < 8 * (g_flag.longest / 8 + 1))
	{
		*flag = 0;
		ft_putchar('\n');
		*n = 0;
	}
	else
	{
		*flag = 1;
		j = 8 * (g_flag.longest / 8 + 1) - ft_strlen(temp);
		while (j-- > 0)
			ft_putchar(' ');
	}
}

void		ft_print_content(char **files, int i, int *len_while)
{
	int		len;
	char	*temp;

	len = ft_strstrlen(files);
	temp = (ft_col(i, len) > len) ? "" : files[ft_col(i, len)];
	ft_putstr(temp);
	if (ft_strlen(temp))
	{
		g_flag.has_print = 1;
		g_flag.print_dir = 1;
	}
	else
		(*len_while)++;
}

void		ft_print_files(char *dir, char **files)
{
	int				i;
	int				n;
	int				len;
	int				len_while;
	int				flag;

	if (g_flag.long_format || g_flag.un || g_flag.m)
	{
		ft_print_un(dir, files);
		return ;
	}
	len_while = ft_strstrlen(files);
	ft_print_init(&flag, &n, &len, len_while);
	ft_check_longest(files);
	i = -1;
	while (++i < len_while)
	{
		ft_print_content(files, i, &len_while);
		ft_print_space((ft_col(i, len) > len) ? "" : files[ft_col(i, len)],
				&flag, &n);
	}
	if (flag)
		ft_putchar('\n');
}

int			ft_check_permission(t_dir dir, DIR **test)
{
	char	*str;

	str = ft_strrchr(dir.dir, '/');
	str = str ? 1 + str : dir.dir;
	if ((*str == '.' && !str[1]) ||
		(g_flag.dot_file || (!g_flag.dot_file && *str != '.')))
	{
		if (g_flag.has_print)
			ft_putchar('\n');
		if (g_flag.print_dir)
		{
			ft_putstr(dir.dir);
			ft_putendl(":");
			g_flag.has_print = 1;
		}
	}
	if (!(*test = opendir(dir.dir)))
	{
		ft_putstr_fd("ft_ls: ", STDERR_FILENO);
		perror(str);
		g_flag.has_print = 1;
		return (0);
	}
	return (1);
}

void		ft_print(t_dir dir)
{
	DIR		*test;
	char	*str;
	char	*cp_files[ft_strstrlen(dir.files)];

	ft_set_content(dir.files, cp_files);
	if (dir.dir)
	{
		if (ft_check_permission(dir, &test))
		{
			str = ft_strrchr(dir.dir, '/');
			str = str ? 1 + str : dir.dir;
			closedir(test);
			if (*str == '.' && !str[1])
				ft_print_files(dir.dir, cp_files);
			else if (g_flag.dot_file || (!g_flag.dot_file && *str != '.'))
				ft_print_files(dir.dir, cp_files);
		}
	}
	else if (*(dir.files))
		ft_print_files(dir.dir, cp_files);
}
