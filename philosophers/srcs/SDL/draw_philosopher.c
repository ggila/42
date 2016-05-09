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

static int		print_philo(SDL_Rect *pos, t_sdlenv *sdle)
{
	SDL_BlitScaled(sdle->img_philo, NULL, sdle->screen, pos);
	return (EXIT_SUCCESS);
}

static int		print_life(SDL_Rect *pos, t_philo *p, t_sdlenv *sdle)
{
	SDL_Surface	*text;
	SDL_Rect	dstrect;
	char		buffer[32];
	char		*tmp;

	tmp = ft_itoa(mutex_get_int(&p->mutex, &p->life));
	ft_strcpy(buffer, tmp);
	ft_strcat(buffer, " / ");
	free(tmp);
	tmp = ft_itoa(MAX_LIFE);
	ft_strcat(buffer, tmp);
	free(tmp);
	text = TTF_RenderText_Solid(sdle->font, buffer, SDL_COL(0, 0, 0));
	dstrect.x = pos->x + pos->h / 2 - text->w / 2;
	dstrect.y = pos->y - text->h;
	SDL_BlitSurface(text, NULL, sdle->screen, &dstrect);
	SDL_FreeSurface(text);
	return (EXIT_SUCCESS);
}

static int		print_state(SDL_Rect *pos, t_philo *p, t_sdlenv *sdle)
{
	SDL_Surface	*text;
	SDL_Rect	dstrect;
	int			state;

	state = mutex_get_int(&p->mutex, &p->state);
	if (state == EAT)
		text = TTF_RenderText_Solid(sdle->font, "EAT", SDL_COL(0xff, 0, 0));
	else if (state == THINK)
		text = TTF_RenderText_Solid(sdle->font, "THINK", SDL_COL(0, 0xff, 0));
	else
		text = TTF_RenderText_Solid(sdle->font, "REST", SDL_COL(0, 0, 0xff));
	dstrect.x = pos->x + pos->h / 2 - text->w / 2;
	dstrect.y = pos->y + pos->h;
	SDL_BlitSurface(text, NULL, sdle->screen, &dstrect);
	SDL_FreeSurface(text);
	return (EXIT_SUCCESS);
}

int				draw_philosopher(t_philo *p, t_sdlenv *sdle)
{
	SDL_Rect	dstrect;
	float		angle;

	angle = (float)p->id * (M_PI * 2.0f) / (float)NB_PHILOSOPHER;
	dstrect.w = WIN_Y / (NB_PHILOSOPHER);
	dstrect.h = WIN_Y / (NB_PHILOSOPHER);
	dstrect.x = WIN_X / 2 + (int)(cos(angle) * (float)(WIN_Y / 3));
	dstrect.x -= dstrect.w / 2;
	dstrect.y = WIN_Y / 2 - (int)(sin(angle) * (float)(WIN_Y / 3));
	dstrect.y -= dstrect.h / 2;
	print_philo(&dstrect, sdle);
	print_life(&dstrect, p, sdle);
	print_state(&dstrect, p, sdle);
	return (EXIT_SUCCESS);
}
