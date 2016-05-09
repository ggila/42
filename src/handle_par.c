/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_par.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 20:08:09 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 21:09:25 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int	ft_check(char line[], char par[], int *len)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("\'\"`{}[]()", line[i]))
		{
			if (ft_strchr("({[", line[i]) && ft_strchr("\'\"`", line[i])
					&& (par[*len] != line[i]))
				return (ft_check_error(line[i]));
			if ((line[i] == ')' && par[*len] != '(')
					|| (line[i] == ']' && par[*len] != '[')
					|| (line[i] == '}' && par[*len] != '{'))
				return (ft_check_error(line[i]));
			else
			{
				line[i] = ' ';
				par[(*len)--] = '\0';
			}
		}
		i++;
	}
	return (OK);
}

int			ft_handle_par(char **cmd, char par[])
{
	char	*tmp;
	int		i;
	int		j;

	i = ft_strlen(par) - 1;
	while (par[0])
	{
		g_line = NULL;
		ft_read_line(par[i]);
		if (ft_check(g_line->line, par, &i) == KO)
			return (KO);
		j = 0;
		ft_linebuf_insert(' ', &j);
		tmp = *cmd;
		*cmd = ft_strjoin(*cmd, g_line->line);
		free(*cmd);
		ft_free_tline();
	}
	return (OK);
}
