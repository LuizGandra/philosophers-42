/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:49:17 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/23 08:49:17 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_rules(int argc, char *argv[])
{
	t_rules *rules;

	rules = get_rules();
	rules->num_philosophers = ft_atoi(argv[1]);
	if (rules->num_philosophers <= 0)
		return (handle_error(ERROR_INVALID_NUM_PHILO, 1));
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->num_meals = ft_atoi(argv[5]);
	else
		rules->num_meals = -1;
	rules->finished = 0;
	return (0);
}
