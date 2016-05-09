/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 09:10:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int	ft_get_tlen(t_line *line)
{
	int len;

	len = 0;
	while (line)
	{
		len += (1 + ft_strlen(line->line));
		line = line->n;
	}
	return (len);
}

char		*ft_get_tline(t_line *line, char c)
{
	char	*cmd;
	int		len;

	while (line->p)
		line = line->p;
	len = ft_get_tlen(line);
	if (!(cmd = (char*)malloc(len + 1)))
		ft_error("malloc failed (ft_get_tline)");
	ft_memclr(cmd, len + 1);
	while (line)
	{
		ft_strcat(cmd, line->line);
		if ((c == INIT) && line->n)
			cmd[ft_strlen(cmd)] = ' ';
		line = line->n;
	}
	return (cmd);
}

static void	ft_tline_init(t_line *new)
{
	new->n = NULL;
	new->p = NULL;
	new->cur_line = 1;
	new->nb_line = 1;
	new->pos = PROMPT_SIZE;
}

void		ft_tline_new(void)
{
	t_line	*new;

	if (!(new = (t_line*)malloc(sizeof(t_line))))
		ft_error("malloc failed (ft_tline_new)");
	ft_tline_init(new);
	if (g_line)
	{
		if (g_line->n)
			g_line->n->p = new;
		new->n = g_line->n;
		g_line->n = new;
		new->p = g_line;
	}
	g_line = new;
}

void		ft_free_tline(void)
{
	t_line	*tmp;

	if (!g_line)
		return ;
	while (g_line->p)
		g_line = g_line->p;
	while (g_line)
	{
		tmp = g_line->n;
		free(g_line);
		g_line = tmp;
	}
	g_line = NULL;
}
