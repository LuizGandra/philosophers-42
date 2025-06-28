/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:41:59 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/27 21:36:09 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*solo_task(void *args)
{
	t_philosopher	*philosopher;
	t_data			*data;

	data = get_data();
	philosopher = (t_philosopher *)args;
	print_state(philosopher, GETTING_FORK);
	while (!has_anyone_died())
		sleep_ms(data->time_to_sleep);
	return (NULL);
}

void	*common_task(void *args)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)args;
	if (philosopher->id % 2 == 0)
		sleep_ms(1);
	while (!has_anyone_died())
	{
		if (has_completed_meals())
			break ;
		p_get_fork(philosopher);
		p_eat(philosopher);
		p_sleep(philosopher);
		p_think(philosopher);
	}
	return (NULL);
}
