/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:41:59 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/26 21:07:14 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*solo_task(void *args)
{
	t_philosopher	*philosopher;
	t_data			*data;

	data = get_data();
	philosopher = (t_philosopher *)args;
	// TODO print_status(philosopher->id, GETTING_FORK);
	// TODO while (!check_death(philosopher->id))
	// 	TODO sleep_ms(data->time_to_sleep);
	return (NULL);
}

void	*common_task(void *args)
{
	// TODO
	(void)args;
	return (NULL);
}
