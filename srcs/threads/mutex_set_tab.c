/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:14:17 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/02 11:02:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_set_tab(pthread_mutex_t *mutex, int *ptr[], int val[], int size)
{
	int	i;

	i = 0;
	pthread_mutex_lock(mutex);
	while (i < size)
	{
		*ptr[i] = val[i];
		i++;
	}
	pthread_mutex_unlock(mutex);
	return ;
}
