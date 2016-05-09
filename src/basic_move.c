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

void	ft_go_up(void)
{
	char	*area;
	char	b[40];

	area = b;
	tputs(tgetstr("up", &area), 1, ft_putchar_tputs);
}

void	ft_go_down(void)
{
	char	*area;
	char	b[40];

	area = b;
	tputs(tgetstr("do", &area), 1, ft_putchar_tputs);
}

void	ft_go_left(void)
{
	char	*area;
	char	b[40];

	area = b;
	tputs(tgetstr("cr", &area), 1, ft_putchar_tputs);
}

void	ft_go_right(void)
{
	char	*res;
	char	*area;
	char	b[40];
	int		size;

	area = b;
	ft_go_left();
	res = tgetstr("nd", &area);
	size = g_disp.size;
	while (--size)
		tputs(res, 1, ft_putchar_tputs);
}

void	ft_pass_prompt(void)
{
	char	*area;
	char	b[40];
	char	*res;
	int		i;

	area = b;
	res = tgetstr("nd", &area);
	i = 0;
	while (i++ < PROMPT_SIZE)
		tputs(res, 1, ft_putchar_tputs);
}
