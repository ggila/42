/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 10:35:55 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_screen_word_insert(char *word, char line_buf[], int cur)
{
	int	i;

	i = 0;
	while (word[i])
		ft_screen_insert(word[i++], line_buf, cur);
}

void	ft_screen_insert(char c, char line_buf[], int cur)
{
	int		i;
	char	buf[40];
	char	*area;

	ft_putchar(c);
	area = buf;
	tputs(tgetstr("sc", &area), 1, ft_putchar_tputs);
	i = 0;
	while (g_disp.cur_line + i != g_disp.nb_line)
	{
		tputs(tgetstr("do", &area), 1, ft_putchar_tputs);
		tputs(tgetstr("cr", &area), 1, ft_putchar_tputs);
		ft_putchar(line_buf[g_disp.size - PROMPT_SIZE
			+ (g_disp.cur_line + i - 1) * g_disp.size]);
		i++;
	}
	tputs(tgetstr("rc", &area), 1, ft_putchar_tputs);
	ft_update_screen_insert_pos(ft_strlen(line_buf));
	if (g_disp.pos == 0)
		ft_go_downleft();
	(void)cur;
}
