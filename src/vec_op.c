/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 14:36:15 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/07 17:49:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	ft_norm(t_pt pt)
{
	double	sqr;

	sqr = sqrt(pt.x * pt.x + pt.y * pt.y);
	return (sqr);
}

t_pt	ft_dot(double a, t_pt v1)
{
	t_pt	pt;

	pt = (t_pt){a * v1.x, a * v1.y};
	return (pt);
}

t_pt	ft_add(t_pt v1, t_pt v2)
{
	t_pt	pt;

	pt = (t_pt){v1.x + v2.x, v1.y + v2.y};
	return (pt);
}
