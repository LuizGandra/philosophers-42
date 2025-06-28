/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:54:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/27 21:49:32 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	validate_args(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		return (handle_error(E_INVALID_ARGS, 0));
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (handle_error(E_INVALID_VAL, 0));
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	has_completed_meals(void)
{
	int	completed_meals;

	pthread_mutex_lock(&get_aux_mutexes()->meals);
	completed_meals = get_data()->has_completed_meals;
	pthread_mutex_unlock(&get_aux_mutexes()->meals);
	return (completed_meals);
}

int	has_anyone_died(void)
{
	int	has_died;

	pthread_mutex_lock(&get_aux_mutexes()->death);
	has_died = get_data()->has_anyone_died;
	pthread_mutex_unlock(&get_aux_mutexes()->death);
	return (has_died);
}
