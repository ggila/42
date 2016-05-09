/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 21:10:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 21:10:52 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void		ft_change_line(int *cur, char buf[])
{
	int	last_cur;
	int	new_len;
	int	end;

	if ((buf[2] == UP && g_line->p) || (buf[2] == DOWN && g_line->n))
	{
		last_cur = *cur;
		g_line = buf[2] == UP ? ft_go_previous_line(g_line, cur)
			: ft_go_next_line(g_line, cur);
		new_len = ft_strlen(g_line->line);
		end = last_cur > new_len ? new_len : last_cur;
		while (end--)
			ft_fleche(RIGHT, cur, g_line->line);
	}
	else if (buf[2] == DOWN)
		ft_new_line(buf, cur);
}
