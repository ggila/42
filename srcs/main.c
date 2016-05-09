/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 19:28:28 by jsaglio           #+#    #+#             */
/*   Updated: 2016/01/30 16:37:22 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_env	g_env;

static int		main_loop(t_env *e)
{
	if (sdl_init(&e->sdle) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	sdl_loop(e);
	sdl_destroy(&e->sdle);
	mutex_destroy_all(e);
	return (EXIT_SUCCESS);
}

int				main(int argc, char *argv[])
{
	if (argc > 1)
	{
		ft_putf_fd(2, "%s: usage : %s\n", argv[0], argv[0]);
		return (EXIT_FAILURE);
	}
	if (NB_PHILOSOPHER < 2)
	{
		ft_putf_fd(2, "%s: Not enough philosophers, edit philo.h\n", argv[0]);
		return (EXIT_FAILURE);
	}
	env_init(&g_env);
	if (thread_create_all(&g_env) == EXIT_FAILURE)
	{
		ft_putf_fd(2, "cannot create threads\n");
		return (EXIT_FAILURE);
	}
	thread_detach_all(&g_env);
	return (main_loop(&g_env));
}
