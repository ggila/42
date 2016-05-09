/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 19:06:28 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/01 15:21:20 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	damage_philosophers(t_env *e)
{
	int	i;
	int state;
	int life;

	i = 0;
	while (i < NB_PHILOSOPHER)
	{
		pthread_mutex_lock(&e->philo[i].mutex);
		state = e->philo[i].state;
		life = e->philo[i].life;
		life = (life < DAMAGE) ? 0 : life - DAMAGE;
		if (state != EAT)
			e->philo[i].life = life;
		if (life <= 0)
		{
			mutex_set_int(&e->mutex, &e->gameover, GAMEOVER_LOSE);
			pthread_mutex_unlock(&e->philo[i].mutex);
			return ;
		}
		pthread_mutex_unlock(&e->philo[i].mutex);
		i++;
	}
	return ;
}

void		*thread_timer(void *arg)
{
	t_env	*e;
	int		clock;

	e = (t_env*)arg;
	clock = 0;
	while (clock < TIMEOUT)
	{
		usleep(MICROSECOND(1));
		damage_philosophers(&g_env);
		if (is_over(e))
			return (NULL);
		clock++;
	}
	mutex_set_int(&e->mutex, &e->gameover, GAMEOVER_WIN);
	return (NULL);
}
