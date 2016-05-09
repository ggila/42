/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 14:57:12 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_opfd(t_rll *new, char redir[], char *file)
{
	if (redir[0] == '<')
		new->fd = open(file, O_RDONLY);
	else
	{
		if (redir[1] == '>')
			new->fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 00777);
		else
			new->fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 00777);
	}
}

int		ft_close_fdr(t_rll *fd)
{
	t_rll	*tmp;

	if (!fd)
		return (OK);
	while (fd)
	{
		tmp = fd;
		if (fd->file)
			free(fd->file);
		if (fd->fd > 0)
			close(fd->fd);
		fd = fd->n;
		free(tmp);
	}
	return (OK);
}

void	ft_close_fdp(t_pll *fd)
{
	while (fd)
	{
		close(fd->fd[0]);
		close(fd->fd[1]);
		fd = fd->n;
	}
}
