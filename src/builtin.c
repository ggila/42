/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 16:54:07 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int			ft_is_builtin(char *cmd)
{
	char *prog;
	char **cmd_words;

	cmd_words = ft_strsplit(cmd, ' ');
	prog = cmd_words[0];
	if (ft_strequ(prog, "clear"))
		return (1);
	else if (ft_strequ(prog, "exit"))
		ft_quit_ok();
	else if (ft_strequ(prog, "unset"))
		return (1);
	else if (ft_strequ(prog, "env"))
		return (1);
	else if (ft_check_setvar(prog))
		return (1);
	else if (ft_strequ(prog, "export"))
		return (1);
	else if (ft_strequ(prog, "cd"))
		return (1);
	ft_free(cmd_words);
	return (0);
}

void		ft_map_builtin(char *cmd)
{
	char *prog;
	char **cmd_words;

	cmd_words = ft_strsplit(cmd, ' ');
	prog = cmd_words[0];
	if (ft_strequ(prog, "clear"))
		ft_clear_screen();
	else if (ft_strequ(prog, "export"))
		ft_sent2setenv(&(cmd_words[1]), 1);
	else if (ft_strequ(prog, "env"))
		ft_putstrstr(g_env);
	else if (ft_check_setvar(prog))
		ft_sent2setenv(cmd_words, 0);
	else if (ft_strequ(prog, "unset"))
		ft_sent2unsetenv(&(cmd_words[1]));
	else if (ft_strequ(prog, "cd"))
		ft_cd(&(cmd_words[1]));
	ft_free(cmd_words);
}
