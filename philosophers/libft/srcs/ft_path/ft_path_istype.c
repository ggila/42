/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_istype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:41:10 by jsaglio           #+#    #+#             */
/*   Updated: 2015/09/25 11:10:04 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_path.h"

int			ft_path_istype(char *path, unsigned int type)
{
	struct stat		sstat;

	if (stat(path, &sstat) < 0)
		return (-1);
	return ((sstat.st_mode & S_IFMT) == type);
}
