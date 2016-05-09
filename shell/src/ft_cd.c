/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:39:54 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int	ft_check(char **cmd)
{
	if (ft_strstrlen(cmd) > 1 || (**cmd == '-' && ft_strlen(*cmd) > 1))
	{
		ft_putendl("cd expect no options and one argument");
		return (KO);
	}
	return (OK);
}

void		ft_change_dir(char *str)
{
	char	*temp;
	char	buf[1000];

	if (!ft_check_dir(str))
	{
		ft_putendl("file does not exist or is not a directory");
		return ;
	}
	if (!(temp = ft_strdup(ft_get_env_value("PWD"))))
		ft_error("ft_strdup failed (ft_change_dir)");
	if (chdir(str) == -1)
		ft_error("error in chdir($HOME)");
	ft_setenv("OLDPWD", temp, 1);
	ft_setenv("PWD", getcwd(buf, 1000), 1);
}

void		ft_cd(char **cmd_words)
{
	ft_set_pwd();
	if (!ft_strstrlen(cmd_words) && ft_just_cd())
		return ;
	if (cmd_words[0][0] == '~')
	{
		if (ft_handle_home(cmd_words) == KO)
			return ;
	}
	if (ft_check(cmd_words) == KO)
		return ;
	else if (ft_strequ(cmd_words[0], "-"))
		ft_handle_oldpwd();
	else if (ft_cdpath(cmd_words[0]) == OK)
		return ;
	else
		ft_change_dir(cmd_words[0]);
}
