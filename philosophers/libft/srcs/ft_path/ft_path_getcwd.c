/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_getcwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:41:10 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/25 11:32:48 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_path.h"
#include <unistd.h>

t_string	*ft_path_getcwd(t_string *path)
{
	if ((ft_string_resize(path, PATH_MAX) < 0)
		|| !getcwd(path->str, path->capacity))
		return (NULL);
	return (path);
}
