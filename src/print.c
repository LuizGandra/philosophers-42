/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:07:00 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/27 21:17:24 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	print_msg(t_philosopher *philosopher, const char *msg);

void	print_state(t_philosopher *philosopher, t_philosopher_state state)
{
	if (state == THINKING)
		print_msg(philosopher, "is thinking");
	else if (state == EATING)
		print_msg(philosopher, "is eating");
	else if (state == SLEEPING)
		print_msg(philosopher, "is sleeping");
	else if (state == GETTING_FORK)
		print_msg(philosopher, "is getting a fork");
	else if (state == DEAD)
		print_msg(philosopher, "has died");
	else
		print_msg(philosopher, "unknown state");
}

static void	print_msg(t_philosopher *philosopher, const char *msg)
{
	pthread_mutex_lock(&get_aux_mutexes()->print);
	if (!has_anyone_died())
		printf("[%i] Philosopher %i - %s\n", get_time(), philosopher->id, msg);
	pthread_mutex_unlock(&get_aux_mutexes()->print);
}
