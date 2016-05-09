/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 21:05:56 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 21:12:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_clear_lineline(t_line *line)
{
	while (line->p)
		line = line->p;
	while (line)
	{
		ft_memclr(line->line, ft_strlen(line->line));
		line = line->n;
	}
}

void	ft_clear_all(t_line *line, char *buf)
{
	ft_clear_lineline(line);
	ft_clear_screen();
	buf[0] = ENTER;
}
