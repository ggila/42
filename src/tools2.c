/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 11:32:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_unify_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\v'
				|| str[i] == '\n' || str[i] == '\r')
			str[i] = ' ';
		i++;
	}
}

char	*ft_get_file(char *cmd)
{
	int		i;
	char	*file;

	i = 0;
	while (ft_strchr("<>", *cmd))
		cmd++;
	while (ft_isspace(*cmd))
		cmd++;
	while (cmd[i] && !ft_isspace(cmd[i]))
		i++;
	if (!(file = ft_strndup(cmd, i)))
		ft_error("malloc failed (ft_strndup)");
	return (file);
}

void	ft_edit_init(int *cur)
{
	*cur = 0;
	g_disp.pos = PROMPT_SIZE;
	g_disp.cur_line = 1;
	g_disp.nb_line = 1;
}

int		ft_check_pipe(char *cmd)
{
	char	flag;

	flag = 1;
	while (*cmd)
	{
		if (flag && *cmd == '|')
		{
			ft_putendl("pipe error");
			return (KO);
		}
		else if (!flag && *cmd == '|')
			flag = 1;
		else if (flag && !ft_isspace(*cmd))
			flag = 0;
		cmd++;
	}
	if (flag)
	{
		ft_putendl("pipe error");
		return (KO);
	}
	return (OK);
}

int		ft_check_error(char c)
{
	ft_putchar(c);
	ft_putendl(" unexpected");
	return (KO);
}
