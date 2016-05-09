/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 16:59:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_rewrite_newline(t_line *line, int cur)
{
	char	*area;
	char	b[40];

	(void)cur;
	area = b;
	tputs(tgetstr("sc", &area), 1, ft_putchar_tputs);
	tputs(tgetstr("ce", &area), 1, ft_putchar_tputs);
	ft_go_downleft();
	tputs(tgetstr("cd", &area), 1, ft_putchar_tputs);
	while (line)
	{
		ft_putstr("    |      --> ");
		ft_putendl(line->line);
		line = line->n;
	}
	tputs(tgetstr("rc", &area), 1, ft_putchar_tputs);
}

void	ft_rewrite(t_line *line, int cur)
{
	char	*area;
	char	b[40];

	area = b;
	tputs(tgetstr("sc", &area), 1, ft_putchar_tputs);
	while (g_line->line[cur])
		ft_fleche(RIGHT, &cur, g_line->line);
	tputs(tgetstr("ce", &area), 1, ft_putchar_tputs);
	ft_go_downleft();
	tputs(tgetstr("cd", &area), 1, ft_putchar_tputs);
	line = line->n;
	while (line)
	{
		ft_putstr("    |      --> ");
		ft_putendl(line->line);
		line = line->n;
	}
	tputs(tgetstr("rc", &area), 1, ft_putchar_tputs);
}
