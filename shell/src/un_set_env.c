/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   un_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:58:53 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_sent2unsetenv(char **cmd_words)
{
	int i;

	i = 0;
	while (cmd_words[i])
	{
		if (ft_unsetenv(cmd_words[i]) == KO)
			ft_putstr("error in ft_unsetenv");
		i++;
	}
}

void	ft_sent2setenv(char **cmd_words, int overwrite)
{
	char	*name;
	char	*value;
	int		i;

	i = 0;
	while (cmd_words[i])
	{
		if (!ft_strchr(cmd_words[i], '=')
				|| !(*(ft_strchr(cmd_words[i], '=') + 1)))
			return ;
		name = cmd_words[i];
		value = ft_strchr(cmd_words[i], '=');
		*value = '\0';
		value++;
		if (ft_setenv(name, value, overwrite) == KO)
			ft_putstr("error in ft_setenv");
		i++;
	}
}

int		ft_check_setvar(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (ft_isspace(str[i++]))
			return (0);
	if (ft_strcount(str, '=') == 0)
		return (0);
	return (1);
}
