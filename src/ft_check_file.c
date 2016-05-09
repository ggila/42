/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:48:09 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int	ft_check_dir(char *path)
{
	struct stat	buf;

	stat(path, &buf);
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

int	ft_check_prog(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == -1)
		return (KO);
	if (S_ISREG(buf.st_mode) && buf.st_mode & 0111)
		return (OK);
	return (KO);
}

int	ft_check_file(char *file)
{
	struct stat	buf;

	if (stat(file, &buf) == -1)
		return (KO);
	if (S_ISREG(buf.st_mode))
		return (OK);
	return (KO);
}
