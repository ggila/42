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
#include <math.h>

int				draw_endgame(int go, t_sdlenv *sdle)
{
	SDL_Surface	*text;
	SDL_Rect	dstrect;

	if (go == GAMEOVER_WIN)
		text = TTF_RenderText_Solid(sdle->font,
			"Now, it's time... to DAAAAAAAANCE!!!", SDL_COL(0, 0xff, 0));
	else
		text = TTF_RenderText_Solid(sdle->font, "RIP...", SDL_COL(0xff, 0, 0));
	dstrect.x = WIN_X / 2 - text->w / 2;
	dstrect.y = 0;
	SDL_BlitSurface(text, NULL, sdle->screen, &dstrect);
	SDL_FreeSurface(text);
	return (EXIT_SUCCESS);
}
