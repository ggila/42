/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 10:34:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	ft_putcwd(void)
{
	char	buf[1000];
	char	*home_dir;
	int		len;

	SET_BLUE;
	getcwd(buf, 1000);
	if (ft_in_env("HOME"))
	{
		home_dir = ft_strjoin("/Volumes/Data", ft_get_env_value("HOME"));
		len = ft_strlen(home_dir);
		if (ft_strnequ(buf, home_dir, len))
		{
			while (len--)
				ft_del_line(0, buf);
			ft_putchar('~');
		}
	}
	ft_putstr(buf);
	SET_BLACK;
}

void		ft_prompt_end(char c)
{
	if (c == INIT)
	{
		ft_putendl("     --------- ");
		ft_putstr("    |      --> ");
	}
	else
	{
		ft_putstr("    |  ");
		ft_putchar(c);
		if (c == HEREDOC)
			ft_putchar(c);
		c == '<' ? ft_putstr("  --> ") : ft_putstr("   --> ");
	}
}

void		ft_prompt_begin(void)
{
	ft_putstr(" -------> in ");
	ft_putcwd();
	ft_putstr("\n     /\n");
}
