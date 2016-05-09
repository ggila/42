/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:40:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int	quit(char *s1, char *s2, char **s3, int s)
{
	free(s1);
	free(s2);
	ft_free(s3);
	return (s);
}

int			ft_just_cd(void)
{
	if (!ft_in_env("HOME"))
		return (1);
	else
		ft_change_dir(ft_get_env_value("HOME"));
	return (1);
}

int			ft_cdpath(char *cmd_words)
{
	char	**cd_path;
	char	*path;
	char	*temp;
	int		i;

	if (ft_in_env("CDPATH"))
	{
		i = 0;
		cd_path = ft_strsplit(ft_get_env_value("CDPATH"), ':');
		while (cd_path[i])
		{
			if (cd_path[i][0] == '~')
				cd_path[i] = ft_sub_home(cd_path[i]);
			temp = ft_strjoin(cd_path[i], "/");
			path = ft_strjoin(temp, cmd_words);
			if (ft_check_dir(path))
			{
				ft_change_dir(path);
				return (quit(temp, path, cd_path, OK));
			}
			i++;
		}
		return (quit(temp, path, cd_path, KO));
	}
	return (KO);
}

int			ft_handle_home(char **cmd_words)
{
	char	*tmp;

	tmp = cmd_words[0];
	cmd_words[0] = ft_sub_home(cmd_words[0]);
	free(tmp);
	if (cmd_words[0][0] == '~')
	{
		ft_putendl("$(HOME) not set");
		return (KO);
	}
	return (OK);
}

void		ft_handle_oldpwd(void)
{
	if (ft_in_env("OLDPWD"))
		ft_change_dir(ft_get_env_value("OLDPWD"));
	else
		ft_putendl("$OLDPWD not set");
}
