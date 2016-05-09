/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/28 10:34:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 21:11:15 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void		ft_line_init(int *cur)
{
	*cur = 0;
	g_disp.cur_line = 1;
	g_disp.pos = PROMPT_SIZE;
}

t_line		*ft_go_previous_line(t_line *line, int *cur)
{
	int	skip;

	if (line->p)
	{
		ft_edit_current_line();
		skip = line->cur_line;
		while (skip-- != 1)
			ft_go_up();
		ft_go_up();
		skip = line->p->nb_line;
		while (skip-- != 1)
			ft_go_up();
		ft_go_left();
		ft_pass_prompt();
		ft_line_init(cur);
		g_disp.nb_line = line->p->nb_line;
	}
	return (line->p);
}

t_line		*ft_go_next_line(t_line *line, int *cur)
{
	ft_edit_current_line();
	while (g_disp.cur_line++ != g_disp.nb_line)
		ft_go_down();
	ft_go_down();
	ft_pass_prompt();
	ft_line_init(cur);
	if (line->n)
		g_disp.nb_line = line->n->nb_line;
	return (line->n);
}

void		ft_go_bottom(t_line *line, int *cur)
{
	line = ft_go_next_line(line, cur);
	while (line)
		line = ft_go_next_line(line, cur);
	ft_go_left();
}
