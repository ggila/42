/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 14:57:08 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void		ft_get_redir(char r[3], char *cmd)
{
	ft_memclr(r, 3);
	if (*cmd == '<')
		r[0] = '<';
	if (*cmd == '>' && cmd[1] == '>')
	{
		r[0] = '>';
		r[1] = '>';
	}
	if (*cmd == '>')
		r[0] = '>';
}

static void		ft_clean(char *cmd)
{
	while (ft_strchr("<>", *cmd))
	{
		*cmd = ' ';
		cmd++;
	}
	while (ft_isspace(*cmd))
		cmd++;
	while (*cmd && !ft_isspace(*cmd))
	{
		*cmd = ' ';
		cmd++;
	}
}

static void		ft_handle(char *cmd, t_rll *fd)
{
	char redir[3];
	char *word;

	ft_get_redir(redir, cmd);
	word = ft_get_file(cmd);
	while (!ft_strequ(redir, fd->redir) && !ft_strequ(fd->file, word))
		fd = fd->n;
	redir[0] == '>' ? dup2(fd->fd, 1) : dup2(fd->fd, 0);
	free(word);
}

void			ft_handle_redir(char *cmd, t_rll *fd)
{
	char flag;

	flag = 1;
	while (*cmd)
	{
		if (flag && ft_strchr("<>", *cmd))
		{
			ft_handle(cmd, fd);
			ft_clean(cmd);
		}
		else if (flag && ft_isalpha(*cmd))
			flag = 0;
		else if (!flag && ft_isspace(*cmd))
			flag = 1;
		cmd += ft_strnequ(cmd, ">>", 2) ? 2 : 1;
	}
}
