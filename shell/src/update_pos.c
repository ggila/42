/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 15:03:15 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_update_screen_insert_pos(int len)
{
	g_disp.pos++;
	if (g_disp.pos % g_disp.size == 0)
	{
		g_disp.pos = 0;
		g_disp.cur_line++;
	}
	if (len < g_disp.size - PROMPT_SIZE)
		g_disp.nb_line = 1;
	else
		g_disp.nb_line = (len - (g_disp.size - PROMPT_SIZE)) / g_disp.size + 2;
}

void	ft_update_updown_pos(int cur, char *line)
{
	(void)cur;
	(void)line;
}
