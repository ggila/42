/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 22:20:29 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int		ft_count(char *dir, char *file)
{
	int				i;
	DIR				*dire;
	struct dirent	*name;

	i = 0;
	if (!(dire = opendir(dir)))
		return (0);
	while ((name = readdir(dire)))
	{
		if (!file || ft_strnequ(name->d_name, file, ft_strlen(file)))
			i++;
	}
	closedir(dire);
	if (!file)
		i -= 2;
	return (i < 0 ? 0 : i);
}

void	ft_fill_fit(char **fit, char *dir, char *file)
{
	int				i;
	DIR				*dire;
	struct dirent	*name;

	i = 0;
	if (!(dire = opendir(dir)))
		return ;
	while ((name = readdir(dire)))
	{
		if ((!file || ft_strnequ(name->d_name, file, ft_strlen(file))) &&
			(!ft_strequ(name->d_name, ".") && !ft_strequ(name->d_name, "..")) &&
			((file && file[0] == '.') || name->d_name[0] != '.'))
		{
			if (!(fit[i] = ft_strdup(name->d_name)))
				ft_error("error in malloc (ft_fill_fit)");
			i++;
		}
	}
	closedir(dire);
}
