/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 17:54:59 by ggilaber          #+#    #+#             */
/*   Updated: 2015/04/02 00:36:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_right_r(void)
{
	ft_rotate_right(R);
}

void	ft_op_init(void)
{
	ft_strcpy(g_op[SA], "SA");
	ft_strcpy(g_op[SB], "SB");
	ft_strcpy(g_op[SS], "SS");
	ft_strcpy(g_op[PA], "PA");
	ft_strcpy(g_op[PB], "PB");
	ft_strcpy(g_op[RA], "RA");
	ft_strcpy(g_op[RB], "RB");
	ft_strcpy(g_op[RR], "RR");
	ft_strcpy(g_op[RRA], "RRA");
	ft_strcpy(g_op[RRB], "RRB");
	ft_strcpy(g_op[RRR], "RRR");
	g_ft_op[SA] = ft_swap_a;
	g_ft_op[SB] = ft_swap_b;
	g_ft_op[SS] = ft_swap_s;
	g_ft_op[PA] = ft_push_a;
	g_ft_op[PB] = ft_push_b;
	g_ft_op[RA] = ft_rotate_left_a;
	g_ft_op[RB] = ft_rotate_left_b;
	g_ft_op[RR] = ft_rotate_left_r;
	g_ft_op[RRA] = ft_rotate_right_a;
	g_ft_op[RRB] = ft_rotate_right_b;
	g_ft_op[RRR] = ft_rotate_right_r;
}

void	ft_init_op_inv(void (*ft_op_inv[11])(void))
{
	ft_op_inv[SA] = ft_swap_a;
	ft_op_inv[SB] = ft_swap_b;
	ft_op_inv[SS] = ft_swap_s;
	ft_op_inv[PA] = ft_push_b;
	ft_op_inv[PB] = ft_push_a;
	ft_op_inv[RA] = ft_rotate_right_a;
	ft_op_inv[RB] = ft_rotate_right_b;
	ft_op_inv[RR] = ft_rotate_right_r;
	ft_op_inv[RRA] = ft_rotate_left_a;
	ft_op_inv[RRB] = ft_rotate_left_b;
	ft_op_inv[RRR] = ft_rotate_left_r;
}
