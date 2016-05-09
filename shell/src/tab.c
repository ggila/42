/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 14:28:56 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	ft_del_word(int *cur, char *line)
{
	while (*cur && !ft_isspace(line[*cur - 1]) && line[*cur - 1] != '/')
		ft_del_pre(cur, line);
}

char		*ft_get_word(int *cur, char *line)
{
	int		i;
	char	*word;

	i = 0;
	while (i < *cur && !ft_isspace(line[*cur - i - 1])
			&& line[*cur - i - 1] != ';')
		i++;
	if (!(word = (char*)malloc(i + 1)))
		ft_error("error in malloc (ft_get_word)");
	ft_memclr(word, i + 1);
	ft_strncpy(word, line + *cur - i, i);
	return (word);
}

char		**ft_get_fit(int *cur, char *line)
{
	char		*word;
	char		**path;
	int			count;
	char		**fit;
	struct stat	buf;

	word = ft_get_word(cur, line);
	path = ft_get_path(word);
	lstat(path[DI], &buf);
	if ((buf.st_mode & S_IFMT) != S_IFDIR)
		return (NULL);
	count = ft_count(path[DI], path[FIL]);
	if (!count || !(fit = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	ft_memclr(fit, sizeof(char*) * (count + 1));
	ft_fill_fit(fit, path[DI], path[FIL]);
	ft_free(path);
	free(word);
	return (fit);
}

static void	ft_replace(int *cur, char *line, char *word)
{
	ft_del_word(cur, line);
	ft_write_word(word, line, cur);
}

void		ft_tab(char *buf, int *cur, char *line)
{
	int		i;
	int		current;
	char	**fit;

	if (!(*cur == ft_strlen(line) || line[*cur] == ' '))
		return ;
	ft_set_pwd();
	fit = ft_get_fit(cur, line);
	if (fit && fit[0])
	{
		i = 100 * ft_strstrlen(fit);
		ft_replace(cur, line, fit[0]);
		read(0, buf, 3);
		while (buf[0] == 9
				|| (buf[0] == 27 && buf[1] == 91 && buf[2] == 90))
		{
			i += buf[0] == 9 || i == 0 ? 1 : -1;
			current = i % ft_strstrlen(fit);
			ft_replace(cur, line, fit[current]);
			read(0, buf, 3);
		}
		ft_free(fit);
	}
}
