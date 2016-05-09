/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 21:10:21 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 21:10:24 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void			ft_write_tline(int fd, t_line *line)
{
	while (line->p)
		line = line->p;
	while (line)
	{
		ft_putnbr_fd(line->pos, fd);
		ft_putstr_fd("|", fd);
		ft_putnbr_fd(line->cur_line, fd);
		ft_putstr_fd("/", fd);
		ft_putnbr_fd(line->nb_line, fd);
		if ((line = line->n))
			ft_putstr_fd(" --> ", fd);
	}
}

void			ft_write_info(int fd, int cur)
{
	ft_putstr_fd("\t\tcur:", fd);
	ft_putnbr_fd(cur, fd);
	ft_putstr_fd("\tg_disp:", fd);
	ft_putnbr_fd(g_disp.pos, fd);
	ft_putstr_fd("/", fd);
	ft_putnbr_fd(g_disp.size, fd);
	ft_putstr_fd("|", fd);
	ft_putnbr_fd(g_disp.cur_line, fd);
	ft_putstr_fd("/", fd);
	ft_putnbr_fd(g_disp.nb_line, fd);
	ft_putstr_fd("\t\tline:", fd);
	ft_write_tline(fd, g_line);
	ft_putstr_fd("\n", fd);
}
