/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:06:01 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/26 21:04:38 by lcosta-g         ###   ########.fr       */
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
	int				num_meals;
	int				has_anyone_died;
	int				finished;
	t_philosopher	*philosophers;
}					t_data;

// VALIDATION
int					validate_args(int argc, char *argv[]);

// INIT
int					init_data(int argc, char *argv[]);
int					init_philosopher(void);

// TASKS
void				*solo_task(void *args);
void				*common_task(void *args);

// HANDLE ERRORS
int					handle_error(const char *error_message);
int					init_aux_mutexes(void);
int					init_task(void);

// GLOBALS
t_data				*get_data(void);
t_aux_mutexes		*get_aux_mutexes(void);

// UTILS
int					ft_strlen(const char *str);
int					ft_atoi(const char *str);

#endif
