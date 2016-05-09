/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 09:49:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/09/06 20:56:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh3.h"

int			main(int ac, char **av, char **env)
{
	char **cmd;

	(void)ac;
	(void)av;
	ft_init(env);
	while (1)
	{
		SET_BLACK;
		cmd = ft_get_cmd();
		SET_WHITE;
		ft_execute(cmd);
		ft_free(cmd);
	}
	return (0);
}
