/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 14:44:28 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static int		already_in(char par[])
{
	int i;

	i = 0;
	while (par[i + 1])
	{
		if (ft_strchr("\'\"`", par[i]))
			return (OK);
	}
	return (KO);
}

static int		ft_check_par1(char c, char par[], int *i)
{
	if (ft_strchr("({[", c))
		par[(*i)++] = c;
	else if (ft_strchr(")}]", c))
	{
		if (i == 0 || (c == ')' && par[*i - 1] != '(')
				|| (c == '}' && par[*i - 1] != '{')
				|| (c == '[' && par[*i - 1] != ']'))
			return (ft_check_error(c));
		else
			par[--(*i)] = '\0';
	}
	return (OK);
}

static int		ft_check_par2(char c, char par[], int *i)
{
	if (*i && par[*i - 1] == c)
	{
		par[--(*i)] = '\0';
		return (OK);
	}
	else if (already_in(par) == OK)
		return (ft_check_error(c));
	else if (*i && ft_strchr("\'\"`", par[*i - 1]) && (c != par[*i - 1]))
		return (ft_check_error(c));
	else
		par[(*i)++] = c;
	return (OK);
}

static int		ft_check_par(char par[], char *cmd)
{
	int	i;

	i = 0;
	while (*cmd)
	{
		if (i > 39)
			return (ft_putendl("can't exceed 40 shades of parenthese"), KO);
		if (ft_strchr("(){}[]", *cmd) && ft_check_par1(*cmd, par, &i) == KO)
			return (KO);
		if (ft_strchr("\'\"`", *cmd) && ft_check_par2(*cmd, par, &i) == KO)
			return (KO);
		if (ft_strchr("(){}[]\'\"`", *cmd))
			*cmd = ' ';
		cmd++;
	}
	return (OK);
}

char			ft_check_end(char **cmd)
{
	char	par[40];

	ft_memclr(par, 40);
	if (ft_get_heredoc(*cmd) == KO)
		return (MISS_EOF);
	if (ft_check_par(par, *cmd) == KO)
		return (MISS_PAR);
	if (par[0] && ft_handle_par(cmd, par) == KO)
		return (MISS_PAR);
	ft_putchar('\n');
	return (0);
}
