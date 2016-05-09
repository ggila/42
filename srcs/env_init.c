/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:41:07 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/01 14:57:20 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_init(t_philo *p, t_chopstick *cs)
{
	int	i;

	i = 0;
	while (i < NB_PHILOSOPHER)
	{
		pthread_mutex_init(&p[i].mutex, NULL);
		p[i].id = i;
		p[i].life = MAX_LIFE;
		p[i].cs[LEFT] = &(cs[i % NB_PHILOSOPHER]);
		p[i].cs[RIGHT] = &(cs[(i + 1) % NB_PHILOSOPHER]);
		i++;
	}
	return ;
}

static void	chopsticks_init(t_chopstick *cs)
{
	int	i;

	i = 0;
	while (i < NB_PHILOSOPHER)
	{
		pthread_mutex_init(&cs[i].mutex, NULL);
		cs[i].philo_id = -1;
		i++;
	}
	return ;
}

void		env_init(t_env *e)
{
	e->gameover = 0;
	ft_bzero(&e->sdle, sizeof(t_sdlenv));
	philo_init(e->philo, e->cs);
	chopsticks_init(e->cs);
	return ;
}
