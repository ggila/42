/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:13:30 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/01 13:45:07 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_detach_all(t_env *e)
{
	int	i;

	i = 0;
	while (i < NB_PHILOSOPHER)
	{
		pthread_detach(e->philo_thread[i]);
		i++;
	}
	pthread_detach(e->timer_thread);
	return ;
}
