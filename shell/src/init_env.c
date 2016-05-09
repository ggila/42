/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 10:52:53 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	ft_cp_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	if (!(g_env = (char**)malloc(sizeof(char*) * (i + 1))))
		ft_error("error occurs in malloc (ft_cp_env())");
	g_env[i] = NULL;
	while (i--)
		if (!(g_env[i] = strdup(env[i])))
			ft_error("error occurs in malloc (ft_cp_env())");
}

void		ft_setup_env(void)
{
	char	buf[1000];

	getcwd(buf, 1000);
	g_env[0] = NULL;
	ft_setenv("PWD", buf, 1);
	ft_setenv("OLDPWD", buf, 1);
	return ;
}

void		ft_init_env(char **env)
{
	int lvl;

	if (*env == NULL)
	{
		g_flag |= MASK_ENV_I;
		if (!(g_env = (char**)malloc(sizeof(char*))))
			ft_error("error in malloc (ft_setup_env)");
		*g_env = NULL;
	}
	else
		ft_cp_env(env);
	if (!ft_in_env("SHLVL"))
		ft_setenv("SHLVL", "0", 1);
	lvl = ft_atoi(ft_get_env_value("SHLVL"));
	ft_setenv("SHLVL", ft_itoa(lvl + 1), 1);
}
