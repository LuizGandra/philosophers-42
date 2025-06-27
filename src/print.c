/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:07:00 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/26 21:18:41 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_msg(int philosopher_id, t_philosopher_state state)
{
	pthread_mutex_lock(&get_aux_mutexes()->print);
	if (!is_philo_dead())
		printf("");
	pthread_mutex_unlock(&get_aux_mutexes()->print);
}