/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:45:02 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/27 19:45:31 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	get_current_time(void);

void	sleep_ms(int ms)
{
	if (ms > 0)
		usleep(ms * 1000);
}

int	get_time(void)
{
	static int	start_time;

	if (start_time == 0)
	{
		start_time = get_current_time();
		return (0);
	}
	return (get_current_time() - start_time);
}

static int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
