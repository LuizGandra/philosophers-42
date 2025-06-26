/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:28:43 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/26 20:06:18 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutex.h"

static t_mutex	*get_mutex(void)
{
	static t_mutex	mutex;

	return (&mutex);
}

int	init_mutex(pthread_mutex_t *mutex)
{
	t_mutex	*mtx;

	mtx = get_mutex();
	if (pthread_mutex_init(mutex, NULL))
		return (EXIT_FAILURE);
	mtx->list[mtx->i] = mutex;
	mtx->i++;
	return (EXIT_SUCCESS);
}

void	clear_mutex(void)
{
	t_mutex	*mtx;

	mtx = get_mutex();
	while (mtx->i > 0)
	{
		mtx->i--;
		pthread_mutex_destroy(mtx->list[mtx->i]);
		mtx->list[mtx->i] = NULL;
	}
}
