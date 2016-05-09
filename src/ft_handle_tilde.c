/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 10:22:38 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	ft_sub_tilde(char *line, int i)
{
	char	*home;

	ft_del_line(i, line);
	home = ft_get_env_value("HOME");
	ft_linebuf_word_insert(home, &i);
}

void		ft_tilde(char *line)
{
	int i;

	if (!ft_in_env("HOME"))
		return ;
	i = 1;
	while (line[i])
	{
		if (line[i] == '~' && line[i - 1])
			ft_sub_tilde(line, i);
		i++;
	}
}

void		ft_handle_tilde(t_line *line)
{
	while (line->p)
		line = line->p;
	while (line)
	{
		ft_tilde(line->line);
		line = line->n;
	}
}
