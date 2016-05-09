/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 10:56:30 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:57:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

char			**ft_get_cmd(void)
{
	char	*cmd;
	char	c;

	cmd = NULL;
	g_line = NULL;
	g_heredoc = NULL;
	ft_prompt_begin();
	ft_read_line(INIT);
	cmd = ft_get_tline(g_line, INIT);
	ft_save_hist(cmd);
	ft_handle_tilde(g_line);
	free(cmd);
	cmd = ft_get_tline(g_line, INIT);
	ft_free_tline();
	c = ft_check_end(&cmd);
	ft_go_upleft();
	ft_putendl("     ---------");
	if (c == MISS_EOF || c == EMPTY)
		return (ft_strsplit("", ';'));
	return (ft_strsplit(cmd, ';'));
}
