/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_isrelative.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:41:10 by jsaglio           #+#    #+#             */
/*   Updated: 2015/10/11 22:08:08 by jsaglio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int		ft_path_isrelative(char *path)
{
	if (ft_strequ(path, ".") || ft_strnequ(path, "./", 2)
		|| ft_strequ(path, "..") || ft_strnequ(path, "../", 3))
		return (1);
	return (0);
}
