/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 19:28:28 by jsaglio           #+#    #+#             */
/*   Updated: 2016/01/29 19:36:30 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "SDL_env.h"

static int	draw(t_env *e)
{
	int i;

	i = 0;
	SDL_FillRect(e->sdle.screen, NULL, 0xffffffff);
	while (i < NB_PHILOSOPHER)
	{
		draw_philosopher(&e->philo[i], &e->sdle);
		draw_chopstick(e);
		i++;
	}
	return (0);
}

int			sdl_loop(t_env *e)
{
	SDL_Event	event;
	int			gameover;

	while (42)
	{
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			break ;
		draw(e);
		if ((gameover = is_over(e)))
		{
			draw_endgame(gameover, &e->sdle);
			if (event.type == SDL_KEYDOWN)
				break ;
		}
		SDL_UpdateWindowSurface(e->sdle.win);
	}
	return (EXIT_SUCCESS);
}
