/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/23 14:30:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_write_word(char *word, char line_buf[], int *cur)
{
	int i;

	i = 0;
	while (word[i])
		ft_write_char(word[i++], line_buf, cur);
}

void	ft_write_char(char c, char line_buf[], int *cur)
{
	ft_linebuf_insert(c, cur);
	ft_screen_insert(c, line_buf, *cur);
}
