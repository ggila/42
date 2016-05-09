/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/28 10:37:11 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 21:42:10 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void			ft_read_line_init(int *cur, char buf[3])
{
	ft_edit_init(cur);
	ft_memclr(buf, 3);
	ft_memclr(g_line->line, 4096);
}

static void		ft_handle_key(char buf[3], int *cur, char c)
{
	if (ft_is_map(buf))
		ft_map(buf, cur, c);
	if (!ft_is_map(buf) && ft_isprint(buf[0]))
	{
		ft_linebuf_insert(buf[0], cur);
		g_flag & MASK_ENV_I ? ft_putchar(buf[0]) :
			ft_screen_insert(buf[0], g_line->line, *cur);
	}
}

void			ft_read_line(char c)
{
	char	buf[3];
	int		cursor;

	ft_tline_new();
	ft_prompt_end(c);
	ft_read_line_init(&cursor, buf);
	while (buf[0] != ENTER)
	{
		ft_memclr(buf, 3);
		read(0, buf, 3);
		ft_handle_key(buf, &cursor, c);
	}
	ft_go_bottom(g_line, &cursor);
}
