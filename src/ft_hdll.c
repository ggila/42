/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/26 19:30:14 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

void	ft_new_hdll(void)
{
	t_hdll	*new;

	if (!(new = (t_hdll*)malloc(sizeof(t_hdll))))
		ft_error("malloc failed (ft_new_hdll)");
	new->n = NULL;
	new->p = g_heredoc ? g_heredoc : NULL;
	new->heredoc = NULL;
	ft_memclr(new->eof, 40);
	if (g_heredoc)
		g_heredoc->n = new;
	g_heredoc = new;
}

void	ft_rewind_hdll(void)
{
	if (!g_heredoc)
		return ;
	while (g_heredoc->p)
		g_heredoc = g_heredoc->p;
}

void	ft_free_hdll(void)
{
	t_hdll	*tmp;

	if (!g_heredoc)
		return ;
	ft_rewind_hdll();
	while (g_heredoc)
	{
		tmp = g_heredoc->n;
		if (g_heredoc->heredoc)
			free(g_heredoc->heredoc);
		free(g_heredoc);
		g_heredoc = tmp;
	}
}
