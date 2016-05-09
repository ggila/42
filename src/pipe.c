/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 17:27:21 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void		ft_last_pipe(char *cmd, t_rll *fd_r, t_pll *fd_p)
{
	dup2(fd_p->fd[1], 1);
	ft_close_fdp(fd_p);
	ft_one_do(cmd, fd_r);
}

static void		ft_middle_pipe(char *cmd, t_rll *fd_r, t_pll *fd_p)
{
	int		pid;
	char	*last_cmd;
	int		status;

	if ((last_cmd = ft_strrchr(cmd, '|')) == NULL)
		ft_last_pipe(cmd, fd_r, fd_p);
	*last_cmd = '\0';
	last_cmd++;
	fd_p = ft_pll_add(fd_p);
	pipe(fd_p->fd);
	if ((pid = fork()) == -1)
		ft_error("fork failed");
	if (pid == 0 && ft_strchr(cmd, '|'))
		ft_middle_pipe(cmd, fd_r, fd_p);
	else if (pid == 0)
		ft_last_pipe(cmd, fd_r, fd_p);
	else
	{
		waitpid(pid, &status, 0);
		dup2(fd_p->fd[0], 0);
		dup2(fd_p->n->fd[1], 1);
		ft_close_fdp(fd_p);
		ft_one_do(last_cmd, fd_r);
	}
}

void			ft_first_pipe(char *cmd, t_rll *fd_r)
{
	t_pll	*fd_p;
	int		pid;
	char	*last_cmd;
	int		status;

	last_cmd = ft_strrchr(cmd, '|');
	*last_cmd = '\0';
	last_cmd++;
	fd_p = ft_pll_new();
	pipe(fd_p->fd);
	if ((pid = fork()) == -1)
		ft_error("fork failed");
	if (pid == 0 && ft_strchr(cmd, '|'))
		ft_middle_pipe(cmd, fd_r, fd_p);
	else if (pid == 0)
		ft_last_pipe(cmd, fd_r, fd_p);
	else
	{
		waitpid(pid, &status, 0);
		dup2(fd_p->fd[0], 0);
		ft_close_fdp(fd_p);
		ft_one_do(last_cmd, fd_r);
	}
}
