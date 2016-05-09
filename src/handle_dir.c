/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:52:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void		ft_set_pwd(void)
{
	char pwd[100];

	if (getcwd(pwd, 100) == NULL)
		ft_error("getcwd() failed");
	if (ft_setenv("PWD", pwd, 1) == KO)
		ft_error("error in ft_setenv");
}

char		*ft_sub_home(char *str)
{
	char *home;
	char *ret;

	if (!(home = ft_in_env("HOME") ?
			ft_strdup(ft_get_env_value("HOME")) : ft_strdup("~/")))
		ft_error("error in ft_strdup (ft_sub_home)");
	if (ft_strequ(str, "~"))
		return (home);
	if (!(ret = (char*)malloc(ft_strlen(str) + ft_strlen(home) + 2)))
		ft_error("malloc fail in ft_get_path");
	ret[0] = '\0';
	ft_strcat(ret, home);
	ft_strcat(ret, "/");
	ft_strcat(ret, str + 2);
	return (ret);
}

static void	ft_make_absolute_path(char **ret, char *str)
{
	char *pwd;
	char buf[1000];

	pwd = getcwd(buf, 1000);
	if (!(ret[PATH] = (char*)malloc(ft_strlen(str) + ft_strlen(pwd) + 2)))
		ft_error("malloc fail in ft_get_path");
	ret[PATH][0] = '\0';
	ft_strcat(ret[PATH], pwd);
	ft_strcat(ret[PATH], "/");
	ft_strcat(ret[PATH], str);
}

char		**ft_get_path(char *str)
{
	char **ret;

	if (!(ret = (char**)malloc(sizeof(char*) * 4)))
		ft_error("malloc fail in ft_get_path");
	ret[3] = NULL;
	if (ft_strnequ(str, "~/", 2))
		ret[PATH] = ft_sub_home(str);
	else if (str[0] == '/')
	{
		if (!(ret[PATH] = ft_strdup(str)))
			ft_error("malloc fail in ft_get_path");
	}
	else
		ft_make_absolute_path(ret, str);
	if (!(ret[DI] = ft_strdup(ret[PATH]))
			|| !(ret[FIL] = ft_strdup(ft_strrchr(ret[PATH], '/') + 1)))
		ft_error("malloc fail in ft_get_path");
	if (str[0] == '/' && !ft_strchr(ret[PATH] + 1, '/'))
		ret[DI][1] = '\0';
	else
		*ft_strrchr(ret[DI], '/') = '\0';
	return (ret);
}

char		*ft_make_path(char *s1, char *s2)
{
	char	*ret;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + 2;
	if (!(ret = (char*)malloc(size)))
		ft_error("malloc failed (ft_make_path)");
	ft_memclr(ret, size);
	ft_strcpy(ret, s1);
	ft_strcat(ret, "/");
	ft_strcat(ret, s2);
	return (ret);
}
