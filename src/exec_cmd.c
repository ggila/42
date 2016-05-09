/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 09:49:24 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void		ft_prepare_exec(void)
{
	struct sigaction	sig;

	sig.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sig, NULL);
	ft_restore_term();
}

static void	ft_wait(pid_t pid, t_rll *fd)
{
	int status;

	if (waitpid(pid, &status, 0) == -1)
		ft_error("waitpid failed");
	ft_close_fdr(fd);
	ft_init_term();
}

static void	ft_first_child(char *cmd, t_rll *fd)
{
	ft_prepare_exec();
	if (!ft_strchr(cmd, '|'))
		ft_one_do(cmd, fd);
	else
		ft_first_pipe(cmd, fd);
}

static void	ft_fork(char *cmd)
{
	pid_t	pid;
	t_rll	*fd;

	fd = NULL;
	if (ft_check_pipe(cmd) == KO || ft_open_fd(cmd, &fd) == KO)
	{
		ft_close_fdr(fd);
		return ;
	}
	if ((pid = fork()) == -1)
		ft_error("fork failed");
	if (pid == 0)
		ft_first_child(cmd, fd);
	else
		ft_wait(pid, fd);
}

void		ft_execute(char **cmd)
{
	while (*cmd)
	{
		if (ft_strlen(ft_strtrim(*cmd)))
		{
			ft_unify_space(*cmd);
			if (ft_is_builtin(*cmd) && !ft_strchr(*cmd, '|'))
				ft_map_builtin(*cmd);
			else
				ft_fork(*cmd);
			ft_putstr("\n");
		}
		cmd++;
	}
}
