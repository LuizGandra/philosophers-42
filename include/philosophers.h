/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:06:01 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/28 12:52:44 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "errors.h"
# include "ft_calloc.h"
# include "mutex.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILOSOPHERS 200

typedef enum e_philosopher_state
{
	THINKING,
	EATING,
	SLEEPING,
	GETTING_FORK,
	DEAD
}					t_philosopher_state;

typedef struct s_aux_mutexes
{
	pthread_mutex_t	print;
	pthread_mutex_t	meals;
	pthread_mutex_t	death;
}					t_aux_mutexes;

typedef struct s_forks
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_forks;

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	int				last_meal_time;
	pthread_t		thread;
	t_forks			forks;
}					t_philosopher;

typedef struct s_data
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				meals_goal;
	int				has_anyone_died;
	int				has_completed_meals;
	t_philosopher	*philosophers;
}					t_data;

// GLOBALS
t_data				*get_data(void);
t_aux_mutexes		*get_aux_mutexes(void);

// INIT
int					init_data(int argc, char *argv[]);
int					init_philosopher(void);
int					init_aux_mutexes(void);
int					init_task(void);

// PRINT
void				print_state(t_philosopher *philosopher,
						t_philosopher_state state);

// STATE
void				p_eat(t_philosopher *philosopher);
void				p_get_fork(t_philosopher *philosopher);
void				p_sleep(t_philosopher *philosopher);
void				p_think(t_philosopher *philosopher);

// TASKS
void				*common_task(void *args);
void				*solo_task(void *args);

// TIME
void				sleep_ms(long long ms);
int					get_time(void);

// UTILS
int					ft_atoi(const char *str);
int					ft_strlen(const char *str);

// VALIDATION
int					has_anyone_died(void);
int					has_completed_meals(void);
int					validate_args(int argc, char *argv[]);

// WATCH
void				watch(void);

#endif
