/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 19:28:28 by jsaglio           #+#    #+#             */
/*   Updated: 2016/01/29 19:36:30 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		mutex_set_int(pthread_mutex_t *mutex, int *i, int value)
{
	pthread_mutex_lock(mutex);
	*i = value;
	pthread_mutex_unlock(mutex);
	return (0);
}
