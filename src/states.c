/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:30:43 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/27 21:37:03 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_get_fork(t_philosopher *philosopher)
{
	if (philosopher->id % 2 == 0)
	{
		pthread_mutex_lock(philosopher->forks.right);
		print_state(philosopher, GETTING_FORK);
		pthread_mutex_lock(philosopher->forks.left);
		print_state(philosopher, GETTING_FORK);
	}
	else
	{
		pthread_mutex_lock(philosopher->forks.left);
		print_state(philosopher, GETTING_FORK);
		pthread_mutex_lock(philosopher->forks.right);
		print_state(philosopher, GETTING_FORK);
	}
}

void	p_eat(t_philosopher *philosopher)
{
	print_state(philosopher, EATING);
	sleep_ms(get_data()->time_to_eat);
	pthread_mutex_lock(&get_aux_mutexes()->meals);
	philosopher->last_meal_time = get_time();
	philosopher->meals_eaten++;
	pthread_mutex_unlock(&get_aux_mutexes()->meals);
	pthread_mutex_unlock(philosopher->forks.left);
	pthread_mutex_unlock(philosopher->forks.right);
}

void	p_sleep(t_philosopher *philosopher)
{
	print_state(philosopher, SLEEPING);
	sleep_ms(get_data()->time_to_sleep);
}

void	p_think(t_philosopher *philosopher)
{
	print_state(philosopher, THINKING);
	sleep_ms(get_data()->time_to_think);
}
