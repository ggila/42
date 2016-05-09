/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:38:23 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int		ft_in_env(char *name)
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strnequ(name, g_env[i], ft_strlen(name)))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_env_value(char *name)
{
	int	i;
	int	len_varname;

	i = 0;
	while (g_env[i])
	{
		len_varname = ft_strchr(g_env[i], '=') - g_env[i];
		if (ft_strnequ(name, g_env[i], len_varname))
			return (ft_strchr(g_env[i], '=') + 1);
		i++;
	}
	return (NULL);
}

int		ft_unsetenv(char *name)
{
	int		i;

	i = 0;
	if (!ft_in_env(name))
		return (OK);
	while (!ft_strnequ(g_env[i], name, ft_strlen(name)))
		i++;
	free(g_env[i]);
	g_env[i] = NULL;
	i++;
	while (g_env[i])
	{
		if (!(g_env[i - 1] = ft_strdup(g_env[i])))
			return (KO);
		g_env[i] = NULL;
		i++;
	}
	return (OK);
}

int		ft_add2env(char *name, char *value)
{
	char	**new;
	int		count;
	int		i;

	count = ft_strstrlen(g_env);
	if (!(new = (char**)malloc(sizeof(char*) * (count + 2))))
		return (KO);
	new[count + 1] = NULL;
	i = 0;
	while (g_env[i])
	{
		if (!(new[i] = ft_strdup(g_env[i])))
			return (KO);
		i++;
	}
	if (!(new[i] = (char*)malloc(ft_strlen(name) + ft_strlen(value) + 2)))
		return (KO);
	ft_memclr(new[i], ft_strlen(name) + ft_strlen(value) + 2);
	ft_strcat(new[i], name);
	ft_strcat(new[i], "=");
	ft_strcat(new[i], value);
	ft_free(g_env);
	g_env = new;
	return (OK);
}

int		ft_setenv(char *name, char *value, int overwrite)
{
	if (!(*name) || (!ft_in_env(name) && !overwrite))
		return (OK);
	if (ft_in_env(name))
		if (ft_unsetenv(name) == KO)
			return (KO);
	return (ft_add2env(name, value) == OK ? OK : KO);
}
