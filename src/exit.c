/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:28:17 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/07/01 18:35:22 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_program(void)
{
	int			i;
	t_data		*data;
	pthread_t	*thread;

	i = 0;
	data = get_data();
	while (i < data->num_philosophers)
	{
		thread = &data->philosophers[i].thread;
		if (pthread_join(*thread, NULL))
			write(2, "Error joining thread\n", 21);
		i++;
	}
	clear_mutex();
	ft_clear_heap();
}
