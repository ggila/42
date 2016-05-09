/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 19:31:11 by jsaglio           #+#    #+#             */
/*   Updated: 2016/02/02 08:07:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_ENV_H
# define SDL_ENV_H

# include "SDL.h"
# include "SDL_ttf.h"

# define WIN_TITLE				"Philosophers"
# define WIN_X					1600
# define WIN_Y					1200
# define FONT_SIZE(X)			((X < 20) ? (50 - 2 * X) : (10))

# define SDL_COL(r ,g , b)		((SDL_Color){r, g, b, 0xff})

typedef struct	s_sdlenv
{
	SDL_Window			*win;
	SDL_Surface			*screen;
	SDL_Surface			*img_philo;
	TTF_Font			*font;
}				t_sdlenv;

int				sdl_init(t_sdlenv *e);
int				sdl_destroy(t_sdlenv *e);

#endif
