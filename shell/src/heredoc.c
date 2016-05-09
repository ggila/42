/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 17:29:10 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int	ft_get_eof(char line[], int i, int count)
{
	int j;

	while (ft_isspace(line[i]))
		i++;
	if (!line[i] || ft_strchr("|>", line[i]))
		return (ft_putendl("expect EOF after <<\n"), KO);
	if (line[i] == '<')
		return (ft_putendl("<<< unexpected\n"), KO);
	ft_new_hdll();
	g_heredoc->nb = 'a' + count;
	j = 0;
	while (line[i + j] && !ft_isspace(line[i + j]) && j < 39)
	{
		g_heredoc->eof[j] = line[i + j];
		line[i + j] = j == 0 ? 'a' + count : ' ';
		j++;
	}
	if (j == 39)
		return (ft_putendl("EOF cannot exceed 40 char\n"), KO);
	return (OK);
}

static int	ft_set_heredoc(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (line[i])
	{
		if (line[i] == '<' && line[i - 1] == '<'
				&& (i == 1 || ft_strchr("; ", line[i - 2])))
		{
			if (ft_get_eof(line, ++i, count) == KO)
				return (-1);
			count++;
		}
		i++;
	}
	if (count > 26)
		ft_putendl("cannot exceed 26 \"<<\"\n");
	return (count > 26 ? -1 : count);
}

static void	ft_read_heredoc(void)
{
	int		len;

	g_line = NULL;
	while (1)
	{
		ft_read_line(HEREDOC);
		len = ft_strlen(g_line->line);
		if (ft_strequ(g_line->line, g_heredoc->eof))
		{
			ft_linebuf_insert('\n', &len);
			ft_memclr(g_line->line, ft_strlen(g_line->line));
			break ;
		}
		ft_linebuf_insert('\n', &len);
	}
	g_heredoc->heredoc = ft_get_tline(g_line, HEREDOC);
	ft_free_tline();
	if (g_heredoc->n)
		g_heredoc = g_heredoc->n;
}

int			ft_get_heredoc(char *cmd)
{
	int	nb;
	int	i;

	SET_WHITE;
	if ((nb = ft_set_heredoc(cmd)) == -1)
		return (ft_free_hdll(), KO);
	SET_BLACK;
	if (nb)
	{
		ft_free_tline();
		ft_rewind_hdll();
		i = 0;
		while (i++ < nb)
			ft_read_heredoc();
		ft_rewind_hdll();
	}
	return (OK);
}
