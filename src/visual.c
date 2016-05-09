/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 16:53:08 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	ft_enhance_cur(char c)
{
	char	*area;
	char	b[40];

	area = b;
	tputs(tgetstr(c == UP ? "vi" : "ve", &area), 1, ft_putchar_tputs);
}

static void	ft_copydel(char c, int start, int end, int *cur)
{
	int		i;
	char	*buf_line;

	buf_line = g_line->line;
	i = -1;
	while (++i < end - start)
		g_tampon[i] = buf_line[start + i];
	g_tampon[i] = '\0';
	if (c == BCK_SP)
	{
		while (*cur != end)
			ft_fleche(*cur < end ? RIGHT : LEFT, cur, buf_line);
		while (*cur != start)
			ft_del_pre(cur, buf_line);
	}
}

static void	ft_restore(char buf[0], int local_cur, int *cur, char buf_line[])
{
	int		end1;
	int		end2;
	char	way;

	way = local_cur <= *cur ? RIGHT : LEFT;
	ft_del_pre(&local_cur, buf_line);
	end1 = local_cur;
	end2 = *cur;
	if (*cur < local_cur)
		end1--;
	while (local_cur != (*cur + 1))
		ft_fleche(way, &local_cur, buf_line);
	ft_del_pre(&local_cur, buf_line);
	if (buf[0] != CTRL_G)
		(end1 < end2) ? ft_copydel(buf[0], end1, end2, cur)
				: ft_copydel(buf[0], end2, end1, cur);
	ft_memclr(buf, 3);
}

void		ft_visual(char buf[], int *cur, char buf_line[])
{
	int		local_cur;

	ft_enhance_cur(UP);
	local_cur = *cur;
	ft_linebuf_word_insert("||", &local_cur);
	ft_screen_word_insert("||", buf_line, local_cur);
	buf[0] = 0;
	while (buf[0] != CTRL_G && buf[0] != SPACE && buf[0] != BCK_SP)
	{
		read(0, buf, 3);
		if (buf[0] == FLECHE && buf[2] % 5 > 1)
		{
			ft_del_pre(&local_cur, buf_line);
			ft_fleche(buf[2], &local_cur, buf_line);
			if (local_cur == *cur)
				ft_fleche(buf[2], &local_cur, buf_line);
			ft_linebuf_insert('|', &local_cur);
			ft_screen_insert('|', g_line->line, local_cur);
		}
	}
	ft_restore(buf, local_cur, cur, buf_line);
	ft_enhance_cur(DOWN);
}
