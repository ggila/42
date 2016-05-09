/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 09:36:39 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int	ft_check_redir(char *cmd)
{
	if (!cmd[1])
		return (KO);
	if (*cmd == '<' && ft_strchr("|>", cmd[1]))
		return (KO);
	if (*cmd == '>' && ft_strchr("<|", cmd[1]))
		return (KO);
	if (*cmd == '>' && cmd[1] == '>')
		if (!cmd[2] || ft_strchr("<|>", cmd[2]))
			return (KO);
	return (OK);
}

static int	ft_check_word(char *words, char redir[])
{
	if (words[0] == '\0' || !ft_isalpha(words[0]))
		return (KO);
	if (redir[0] == '<' && ft_check_file(words) == KO)
		return (KO);
	return (OK);
}

static int	ft_add_redir(char *cmd, t_rll **fd)
{
	char	*word;
	t_rll	*new;

	if (ft_strnequ(cmd, "<<", 2))
		return (OK);
	if (!(new = (t_rll*)malloc(sizeof(t_rll))))
		ft_error("malloc failed (ft_add_redir)");
	new->n = *fd;
	new->file = NULL;
	new->fd = -1;
	ft_memclr(new->redir, 3);
	new->redir[0] = *cmd;
	if (cmd[0] == '>' && cmd[1] == '>')
		new->redir[1] = '>';
	word = ft_get_file(cmd);
	if (ft_check_word(word, new->redir) == KO)
	{
		ft_putstr("expected regular filename, ");
		free(word);
		return (KO);
	}
	new->file = word;
	ft_opfd(new, new->redir, new->file);
	*fd = new;
	return (OK);
}

int			ft_open_fd(char *cmd, t_rll **fd)
{
	char	flag;

	flag = 1;
	while (*cmd)
	{
		if (flag && ft_strchr("<>", *cmd))
		{
			if (ft_check_redir(cmd) == KO
				|| ft_add_redir(cmd, fd) == KO)
			{
				ft_putendl("error in redirection");
				return (KO);
			}
		}
		else if (flag && ft_isalpha(*cmd))
			flag = 0;
		else if (!flag && ft_isspace(*cmd))
			flag = 1;
		cmd += ft_strnequ(cmd, ">>", 2) || ft_strnequ(cmd, "<<", 2) ? 2 : 1;
	}
	return (OK);
}
