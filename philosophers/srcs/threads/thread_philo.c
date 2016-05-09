/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:38:15 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/02 11:11:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define EAT_TRIGGER 	((int)(0.8f * (float)MAX_LIFE))

static char			cs_available(t_philo *p)
{
	if (pthread_mutex_trylock(&(p->cs[LEFT]->mutex)) != 0)
		return (0);
	if (pthread_mutex_trylock(&(p->cs[RIGHT]->mutex)) != 0)
	{
		pthread_mutex_unlock(&p->cs[LEFT]->mutex);
		return (0);
	}
	return (1);
}

static char			eat(t_philo *p)
{
	mutex_set_tab(&p->mutex, (int*[]){&p->state, &p->life},
			(int[]){EAT, MAX_LIFE}, 2);
	usleep(MICROSECOND(EAT_T));
	pthread_mutex_unlock(&p->cs[LEFT]->mutex);
	pthread_mutex_unlock(&p->cs[RIGHT]->mutex);
	return (1);
}

static char			rest(t_philo *p)
{
	mutex_set_tab(&p->mutex, (int*[]){&p->state}, (int[]){REST}, 1);
	usleep(MICROSECOND(REST_T));
	return (0);
}

static int			think(t_philo *p)
{
	mutex_set_tab(&p->mutex, (int*[]){&p->state}, (int[]){THINK}, 1);
	usleep(MICROSECOND(THINK_T));
	return (0);
}

void				*thread_philo(void *arg)
{
	t_philo	*p;
	int		should_eat;
	char	state;

	p = (t_philo*)arg;
	while (1)
	{
		if (is_over(&g_env))
			break ;
		state = mutex_get_int(&p->mutex, &p->state);
		should_eat = (mutex_get_int(&p->mutex, &p->life) <= EAT_TRIGGER);
		if (state == EAT)
			rest(p);
		else
		{
			if (should_eat && cs_available(p))
				eat(p);
			else
				think(p);
		}
	}
	return (NULL);
}
