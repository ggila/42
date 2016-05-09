/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prog_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:50:43 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int	ft_try_this_path(char *path, char **cmd_words)
{
	char	*test;

	test = ft_make_path(path, cmd_words[0]);
	if (ft_check_prog(test) == OK)
	{
		free(cmd_words[0]);
		cmd_words[0] = test;
		return (OK);
	}
	free(test);
	return (KO);
}

int			ft_get_prog_path(char **cmd_words)
{
	char	**path;
	int		i;

	if (ft_check_prog(cmd_words[0]) == OK)
		return (OK);
	if (!ft_in_env("PATH"))
		return (KO);
	path = ft_strsplit(ft_get_env_value("PATH"), ':');
	i = 0;
	while (path[i])
		if (ft_try_this_path(path[i++], cmd_words) == OK)
			return (OK);
	free(path);
	return (KO);
}
