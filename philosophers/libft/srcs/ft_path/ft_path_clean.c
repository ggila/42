/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:41:10 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/24 21:14:42 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

static void		ft_clean_double_slash(char *path)
{
	char	*s_i;
	char	*s_j;

	s_i = path;
	s_j = path;
	while ((s_i[0] = s_j[0]))
	{
		if (ft_strncmp(s_j, "//", 2))
		{
			s_i++;
			s_j++;
			continue ;
		}
		s_j++;
	}
	if ((ft_strlen(path) > 1) && (s_i[-1] == '/'))
		s_i[-1] = 0;
	return ;
}

static void		ft_clean_same_dir(char *path)
{
	char	*s_i;
	char	*s_j;

	s_i = path;
	s_j = path;
	while ((s_i[0] = s_j[0]))
	{
		if (ft_strncmp(s_j, "/./", 3))
		{
			s_i++;
			s_j++;
			continue ;
		}
		s_j += 2;
	}
	if (ft_strequ(path, "/."))
		path[1] = 0;
	if ((ft_strlen(path) > 2) && ft_strequ(s_i - 2, "/."))
		s_i[-2] = 0;
	return ;
}

static void		ft_clean_parent(char *path)
{
	char	*cursor;
	char	*s_i;

	s_i = path;
	while (s_i[0])
	{
		if (ft_strnequ(s_i, "/../", 4))
		{
			s_i[0] = 0;
			if (!(cursor = ft_strrchr(path, '/')))
				cursor = path;
			ft_strcpy(cursor, s_i + 3);
			s_i = cursor;
			continue ;
		}
		s_i++;
	}
	return ;
}

static void		ft_clean_trailing_dotdot(char *path)
{
	char	*cursor;

	if (ft_strequ(path, "/.."))
	{
		path[1] = 0;
		return ;
	}
	cursor = ft_strrchr(path, '/');
	if (cursor && ft_strequ(cursor, "/.."))
	{
		cursor[0] = 0;
		cursor = ft_strrchr(path, '/');
		if (cursor == path)
			cursor[1] = 0;
		else
			cursor[0] = 0;
	}
	return ;
}

void			ft_path_clean(char *path)
{
	if (!path)
		return ;
	ft_clean_double_slash(path);
	ft_clean_same_dir(path);
	if (path[0] == '/')
	{
		ft_clean_parent(path);
		ft_clean_trailing_dotdot(path);
	}
	return ;
}
