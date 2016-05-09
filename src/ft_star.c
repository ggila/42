/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 15:48:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

static void	ft_del_word(int *cur, char *line)
{
	while (*cur && !ft_isspace(line[*cur - 1]))
		ft_del_pre(cur, line);
}

static void	ft_print_fit(char *fit, char *word, int *cur, char *line)
{
	int len;

	len = ft_strlen(word);
	if (ft_strchr("./", word[len - 1]))
		ft_write_word(word, line, cur);
	if (word[len - 1] == '.' && word[len - 2] == '/')
		ft_del_pre(cur, line);
	ft_write_word(fit, line, cur);
	ft_write_char(' ', line, cur);
}

void		ft_star(int *cur, char *line)
{
	char	**fit;
	char	*word;
	int		i;

	ft_del_pre(cur, line);
	word = ft_get_word(cur, line);
	fit = ft_get_fit(cur, line);
	if (fit && fit[0])
	{
		ft_del_word(cur, line);
		i = 0;
		while (fit[i])
			ft_print_fit(fit[i++], word, cur, line);
		ft_free(fit);
	}
	else
		ft_write_char('*', line, cur);
	free(word);
}
