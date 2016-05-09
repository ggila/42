/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plug_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 09:46:32 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static char	*ft_get_hd(char c, t_hdll *hdll)
{
	while (hdll->nb != c)
		hdll = hdll->n;
	return (hdll->heredoc);
}

static char	*ft_get_text(char *cmd)
{
	char	*txt;

	txt = NULL;
	while ((cmd = ft_strchr(cmd, '<')))
	{
		if (*(cmd + 1) == '<')
		{
			*cmd = ' ';
			*(cmd + 1) = ' ';
			cmd += 2;
			while (ft_isspace(*cmd))
				cmd++;
			txt = ft_strjoin(txt, ft_get_hd(*cmd, g_heredoc));
			*cmd = ' ';
		}
		else
			cmd++;
	}
	return (txt);
}

static void	ft_write_hd(int fd[2], char *text)
{
	if (pipe(fd) == -1)
		ft_error("pipe failed (ft_write_hd)");
	dup2(fd[0], 0);
	ft_putstr_fd(text, fd[1]);
	close(fd[1]);
}

void		ft_plug_heredoc(char *cmd, int fd[2])
{
	char	*text;

	text = ft_get_text(cmd);
	if (text)
		ft_write_hd(fd, text);
}
