/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:51:39 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/26 21:07:26 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_forks(t_forks *forks, int i);

int	init_data(int argc, char *argv[])
{
	t_data	*data;

	data = get_data();
	data->num_philosophers = ft_atoi(argv[1]);
	if (data->num_philosophers <= 0
		|| data->num_philosophers > MAX_PHILOSOPHERS)
		return (handle_error(E_INVALID_PHILOS));
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->time_to_think = data->time_to_die - data->time_to_eat
		- data->time_to_sleep;
	if (data->time_to_think > 5)
		data->time_to_think = 5;
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	else
		data->num_meals = -1;
	data->finished = 0;
	data->philosophers = (t_philosopher *)ft_calloc(sizeof(t_philosopher)
			* data->num_philosophers);
	return (EXIT_SUCCESS);
}

int	init_philosopher(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	i = 0;
	while (i < data->num_philosophers)
	{
		data->philosophers[i].id = i + 1;
		if (init_forks(&data->philosophers[i].forks, i) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_aux_mutexes(void)
{
	t_aux_mutexes	*aux_mtx;

	aux_mtx = get_aux_mutexes();
	if (init_mutex(&(aux_mtx->print)))
		return (handle_error(E_MUTEX_INIT));
	if (init_mutex(&(aux_mtx->meals)))
		return (handle_error(E_MUTEX_INIT));
	if (init_mutex(&(aux_mtx->death)))
		return (handle_error(E_MUTEX_INIT));
	return (EXIT_SUCCESS);
}

static int	init_forks(t_forks *forks, int i)
{
	static t_forks			*first_forks;
	static pthread_mutex_t	*last_fork;

	if (i == 0)
	{
		forks->right = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t));
		if (init_mutex(forks->right) != 0)
			return (EXIT_FAILURE);
		last_fork = forks->right;
		first_forks = forks;
	}
	else
	{
		forks->right = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t));
		if (init_mutex(forks->right) != 0)
			return (EXIT_FAILURE);
		forks->left = last_fork;
		last_fork = forks->right;
		if (i == get_data()->num_philosophers - 1)
			first_forks->left = forks->right;
	}
	return (EXIT_SUCCESS);
}

int	init_task(void)
{
	t_philosopher	*philosopher;
	t_data			*data;
	int				i;

	data = get_data();
	if (data->num_philosophers == 1)
	{
		philosopher = &data->philosophers[0];
		if (pthread_create(&philosopher->thread, NULL,
				&solo_task, philosopher) != 0)
			return (handle_error(E_THREAD_INIT));
	}
	else
	{
		i = 0;
		while (i < data->num_philosophers)
		{
			philosopher = &data->philosophers[i];
			if (pthread_create(&philosopher->thread, NULL,
					&common_task, philosopher) != 0)
				return (handle_error(E_THREAD_INIT));
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
