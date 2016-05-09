/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaglio <jsaglio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 19:31:11 by jsaglio           #+#    #+#             */
/*   Updated: 2016/02/02 11:12:36 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include "SDL_env.h"

# include <stdlib.h>
# include <pthread.h>
# include <time.h>

/*
** DO NOT EDIT
*/

# define MICROSECOND(X)		(1000000 * X)
# define GAMEOVER_WIN		1
# define GAMEOVER_LOSE		-1
# define LEFT				0
# define RIGHT				1

/*
** PARAMETERS THAT CAN BE CHANGED BELOW
*/

# define NB_PHILOSOPHER		7
# define MAX_LIFE			10
# define EAT_T				1
# define REST_T				1
# define THINK_T			1
# define DAMAGE				1
# define TIMEOUT			60

/*
** Chopstick:
** - philo_id is the ID of the philosopher handling the stick
*/

typedef struct	s_chopstick
{
	pthread_mutex_t		mutex;
	int					philo_id;
}				t_chopstick;

/*
** Philo:
** - philo_id is the ID of the philosopher
*/

enum	e_state
{
	EAT = 0,
	THINK,
	REST
};

typedef struct	s_philo
{
	pthread_mutex_t		mutex;
	int					id;
	int					life;
	int					state;
	t_chopstick			*cs[2];
}				t_philo;

/*
** Env structure:
*/

typedef struct	s_env
{
	pthread_t		timer_thread;
	pthread_t		sdl_thread;
	pthread_t		philo_thread[NB_PHILOSOPHER];
	t_philo			philo[NB_PHILOSOPHER];
	t_chopstick		cs[NB_PHILOSOPHER];
	t_sdlenv		sdle;
	pthread_mutex_t	mutex;
	int				gameover;
}				t_env;

/*
** Global
*/

extern t_env	g_env;

void			env_init(t_env *env);

int				thread_create_all(t_env *e);
void			thread_detach_all(t_env *env);
int				mutex_destroy_all(t_env *e);
int				mutex_get_int(pthread_mutex_t *mutex, int *i);
int				mutex_set_int(pthread_mutex_t *mutex, int *i, int value);
void			mutex_set_tab(pthread_mutex_t *mutex,
					int *ptr[], int val[], int size);

int				is_over(t_env *e);
void			*thread_philo(void *arg);
void			*thread_timer(void *arg);

int				sdl_loop(t_env *e);
int				draw_philosopher(t_philo *p, t_sdlenv *sdle);
int				draw_chopstick(t_env *e);
int				draw_endgame(int go, t_sdlenv *sdle);

#endif
