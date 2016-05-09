/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:56:16 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 21:40:19 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	ft_move(int n, int *cur, char line_buf[])
{
	int	end;

	end = (n == CTRL_A) ? 0 : ft_strlen(line_buf);
	while (*cur != end)
		ft_fleche(n == CTRL_A ? LEFT : RIGHT, cur, line_buf);
}

static void	ft_move_word(int n, int *cur, char line_buf[])
{
	if (!line_buf[*cur] && (n == LEFT))
		ft_fleche(LEFT, cur, line_buf);
	if ((*cur == 0) && (n == RIGHT))
		ft_fleche(RIGHT, cur, line_buf);
	while (line_buf[*cur] && *cur && ft_isspace(line_buf[*cur]))
		ft_fleche(n == LEFT ? LEFT : RIGHT, cur, line_buf);
	while (line_buf[*cur] && *cur > 0 && !ft_isspace(line_buf[*cur]))
		ft_fleche(n == LEFT ? LEFT : RIGHT, cur, line_buf);
}

int			ft_is_map(char buf[])
{
	char c;

	c = buf[0];
	if (c == FLECHE || c == CTRL_D)
		return (1);
	else if (c == ENTER)
		return (1);
	else if (c == DEL1 && c == DEL2)
		return (1);
	else if (c == BCK_SP)
		return (1);
	else if (c == TAB || c == CTRL_A)
		return (1);
	else if (c == CTRL_E)
		return (1);
	else if (c == WORD && buf[2] != 0)
		return (1);
	else if (c == CTRL_N || c == CTRL_L)
		return (1);
	else if (c == CTRL_G)
		return (1);
	else if (c == CTRL_P)
		return (1);
	return (0);
}

void		ft_map2(char *buf, int *cur, char c)
{
	if (buf[0] == FLECHE && buf[2] % 5 > 1)
		ft_fleche(buf[2], cur, g_line->line);
	else if (buf[0] == FLECHE && !(g_flag & MASK_ENV_I) && c == INIT)
		ft_hist(buf[2], cur, g_line->line);
	else if (buf[0] == DEL1 && buf[1] == DEL2)
		ft_del(*cur, g_line->line);
	else if (buf[0] == BCK_SP)
		ft_del_pre(cur, g_line->line);
	else if (buf[0] == CTRL_A || buf[0] == CTRL_E)
		ft_move(buf[0], cur, g_line->line);
	else if (buf[0] == WORD && (buf[2] == RIGHT || buf[2] == LEFT))
		ft_move_word(buf[2], cur, g_line->line);
	else if (c == INIT && buf[0] == WORD
				&& (buf[2] == UP || buf[2] == DOWN))
		ft_change_line(cur, buf);
	else if (c == INIT && buf[0] == CTRL_N && !g_line->n)
		ft_new_line(buf, cur);
	else if (buf[0] == CTRL_L)
		ft_clear_all(g_line, buf);
}

void		ft_map(char *buf, int *cur, char c)
{
	if (buf[0] == TAB && !(g_flag & MASK_ENV_I && c == INIT))
		ft_tab(buf, cur, g_line->line);
	if (buf[0] == CTRL_D)
	{
		ft_putendl("\n");
		ft_quit_ok();
	}
	else if (buf[0] == CTRL_G && !(g_flag && MASK_ENV_I) && c == INIT)
		ft_visual(buf, cur, g_line->line);
	else if (buf[0] == CTRL_P)
	{
		ft_linebuf_word_insert(g_tampon, cur);
		ft_screen_word_insert(g_tampon, g_line->line, *cur);
		ft_memclr(g_tampon, ft_strlen(g_tampon));
	}
	else
		ft_map2(buf, cur, c);
}
