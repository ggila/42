/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 18:39:29 by ggilaber          #+#    #+#             */
/*   Updated: 2015/01/21 22:31:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_count(char *str)
{
	int	i;
	DIR	*dir;

	i = 0;
	if (!(dir = opendir(str)))
		return (0);
	while (readdir(dir))
		i++;
	closedir(dir);
	if (g_flag.a)
		i -= 2;
	return (i);
}

int		ft_col(int i, int nb_file)
{
	int col;
	int nb_col;
	int nb_line;

	if (g_flag.un)
		return (i);
	col = 8 * (g_flag.longest / 8 + 1);
	nb_col = g_flag.term_size / col;
	if (!nb_col)
		++nb_col;
	nb_line = nb_file / nb_col + !!(nb_file % nb_col);
	return (nb_line * (i % nb_col) + i / nb_col);
}

char	*ft_make_path(char *dir, char *file)
{
	char	*str;
	int		len;

	if (!dir && !(str = ft_strdup(file)))
		return (NULL);
	else
	{
		len = 2 + ft_strlen(file) + ft_strlen(dir);
		if (!(str = (char*)malloc(sizeof(char) * len)))
			return (NULL);
		str[0] = '\0';
		ft_strcat(str, dir);
		ft_strcat(str, "/");
		ft_strcat(str, file);
	}
	return (str);
}

void	ft_set_key_sort(char **file, t_key_sort tab[], char c)
{
	int i;

	i = -1;
	if (c == '<')
	{
		while (file[++i])
			file[i] = tab[i].str;
	}
	else if (c == '>')
	{
		while (file[++i])
			tab[i].str = file[i];
	}
}

int		ft_count_digit(int n)
{
	int i;

	i = 1;
	while ((n = n / 10) > 0)
		i++;
	return (i);
}
