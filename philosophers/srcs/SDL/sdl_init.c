/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 19:28:28 by jsaglio           #+#    #+#             */
/*   Updated: 2016/01/29 16:16:58 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		load_media(t_sdlenv *sdle)
{
	if (!(sdle->img_philo = SDL_LoadBMP("media/alhazen.bmp"))
		|| !(sdle->font = TTF_OpenFont("media/arial_black.ttf",
							FONT_SIZE(NB_PHILOSOPHER))))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				sdl_init(t_sdlenv *sdle)
{
	if (SDL_Init(SDL_INIT_VIDEO) || TTF_Init())
	{
		ft_putf_fd(2, "SDL: Failure during initialisation");
		return (EXIT_FAILURE);
	}
	sdle->win = SDL_CreateWindow(WIN_TITLE,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_X, WIN_Y,
		SDL_WINDOW_SHOWN);
	if (!sdle->win
		|| !(sdle->screen = SDL_GetWindowSurface(sdle->win))
		|| (load_media(sdle) == EXIT_FAILURE))
	{
		ft_putf_fd(2, "SDL: Failure during initialisation");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
