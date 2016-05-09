/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 15:13:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_go_upleft(void)
{
	ft_go_up();
	ft_go_left();
}

void	ft_go_downleft(void)
{
	ft_go_down();
	ft_go_left();
}

void	ft_go_upright(void)
{
	ft_go_up();
	ft_go_right();
}

void	ft_go_downright(void)
{
	ft_go_down();
	ft_go_right();
}
