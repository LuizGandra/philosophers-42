/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:16:18 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/07/01 18:23:38 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_philosopher_dead(t_philosopher *philosopher);
static int	completed_all_meals(void);

void	watch(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	while (1)
	{
		i = 0;
		while (i < data->num_philosophers)
		{
			if (is_philosopher_dead(&data->philosophers[i]))
				return ;
			if (completed_all_meals())
				return ;
			i++;
		}
	}
}

static int	is_philosopher_dead(t_philosopher *philosopher)
{
	t_data	*data;

	data = get_data();
	pthread_mutex_lock(&get_aux_mutexes()->meals);
	if (get_time() - philosopher->last_meal_time > data->time_to_die)
	{
		pthread_mutex_unlock(&get_aux_mutexes()->meals);
		print_state(philosopher, DEAD);
		pthread_mutex_lock(&get_aux_mutexes()->death);
		data->has_anyone_died = 1;
		pthread_mutex_unlock(&get_aux_mutexes()->death);
		return (1);
	}
	pthread_mutex_unlock(&get_aux_mutexes()->meals);
	return (0);
}

static int	completed_all_meals(void)
{
	t_data	*data;
	int		count;
	int		i;

	data = get_data();
	count = 0;
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_lock(&get_aux_mutexes()->meals);
		if (data->philosophers[i].meals_eaten >= data->meals_goal
			&& data->meals_goal > 0)
			count++;
		pthread_mutex_unlock(&get_aux_mutexes()->meals);
		i++;
	}
	if (count == data->num_philosophers)
	{
		pthread_mutex_lock(&get_aux_mutexes()->meals);
		data->has_completed_meals = 1;
		pthread_mutex_unlock(&get_aux_mutexes()->meals);
		return (1);
	}
	return (0);
}
