/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 19:00:08 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_clear_screen(void)
{
	char	*res;
	char	*area;
	char	b[40];

	area = b;
	res = tgetstr("cl", &area);
	tputs(res, 1, ft_putchar_tputs);
}

void	ft_tabcpy(char *line, char temp[], int cur)
{
	int	i;

	i = 0;
	while (line[i])
	{
		temp[i] = line[i + cur];
		i++;
	}
}

int		ft_putchar_tputs(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_lineclr(char *line)
{
	int i;

	i = 0;
	while (line[i])
		line[i++] = '\0';
}
