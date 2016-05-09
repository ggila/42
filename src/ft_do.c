/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 10:56:27 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_one_do(char *cmd, t_rll *fd)
{
	char	**cmd_words;
	int		fd_hd[2];

	ft_plug_heredoc(cmd, fd_hd);
	ft_handle_redir(cmd, fd);
	cmd_words = ft_strsplit(cmd, ' ');
	ft_wildcard_explode(&cmd_words);
	if (ft_is_builtin(cmd_words[0]))
	{
		ft_map_builtin(cmd_words[0]);
		exit(0);
	}
	else if (ft_get_prog_path(cmd_words) == KO)
		ft_error("prog does not exist, can't handle this");
	execve(cmd_words[0], cmd_words, g_env);
	ft_error("execve failed");
}
