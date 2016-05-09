/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_get_folder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:41:10 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/13 15:11:50 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_str.h"

int		ft_path_get_folder(t_string *buf, char *path)
{
	char	*file;

	if (!buf || !path)
		return (-1);
	if ((file = ft_strrchr(path, '/')))
	{
		file++;
		ft_string_ncpy(buf, path, file - path);
		return (0);
	}
	ft_string_clear(buf);
	return (0);
}
