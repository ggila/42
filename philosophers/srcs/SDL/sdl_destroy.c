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

#include "SDL_env.h"

int		sdl_destroy(t_sdlenv *sdle)
{
	SDL_FreeSurface(sdle->screen);
	SDL_DestroyWindow(sdle->win);
	TTF_CloseFont(sdle->font);
	TTF_Quit();
	SDL_Quit();
	return (EXIT_SUCCESS);
}
