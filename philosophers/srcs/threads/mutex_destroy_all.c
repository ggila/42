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

int	mutex_destroy_all(t_env *e)
{
	int	i;

	i = 0;
	while (i < NB_PHILOSOPHER)
	{
		pthread_mutex_destroy(&(e->philo[i].mutex));
		pthread_mutex_destroy(&(e->cs[i].mutex));
		i++;
	}
	pthread_mutex_destroy(&(e->mutex));
	return (EXIT_SUCCESS);
}
