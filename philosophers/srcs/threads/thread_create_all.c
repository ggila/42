/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 18:42:32 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/30 16:38:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_create_all(t_env *e)
{
	int	i;

	i = 0;
	while (i < NB_PHILOSOPHER)
	{
		if (pthread_create(&(e->philo_thread[i]), NULL, &thread_philo,
					&(e->philo[i])))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_create(&(e->timer_thread), NULL, thread_timer, e))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
