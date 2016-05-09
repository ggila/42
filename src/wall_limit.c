/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_limit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/08 15:48:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/23 11:36:35 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_sky_limit(double dist)
{
	if (dist < 3)
		return (IM_HEIGHT);
	else
		return (200 + 600 / dist);
}

int		get_ground_limit(double dist)
{
	if (dist < 3)
		return (0);
	else
		return (200 - 600 / dist);
}
