/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 14:13:13 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void		ft_linebuf_insert(char c, int *cur)
{
	char	temp[4096];
	int		len;
	int		i;

	len = ft_strlen(g_line->line);
	ft_memclr(temp, len + 3);
	if (*cur == 4000)
		ft_error("too long, fuck it");
	if (*cur != len)
	{
		ft_tabcpy(g_line->line, temp, *cur);
		g_line->line[*cur] = c;
		i = 0;
		while (temp[i])
		{
			g_line->line[*cur + i + 1] = temp[i];
			i++;
		}
		g_line->line[*cur + i + 1] = '\0';
	}
	else
		g_line->line[*cur] = c;
	*cur += 1;
}

void		ft_linebuf_word_insert(char *word, int *cur)
{
	int i;

	i = 0;
	while (word[i])
	{
		ft_linebuf_insert(word[i], cur);
		i++;
	}
}
