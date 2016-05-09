/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/28 11:09:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 21:11:40 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_edit_current_line(void)
{
	g_line->cur_line = g_disp.cur_line;
	g_line->nb_line = g_disp.nb_line;
}

void	ft_new_line(char buf[], int *cur)
{
	while (g_line->line[*cur])
		ft_fleche(RIGHT, cur, g_line->line);
	ft_edit_current_line();
	ft_edit_init(cur);
	ft_tline_new();
	ft_read_line_init(cur, buf);
	ft_putstr("\n    |      --> ");
}
