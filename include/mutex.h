/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:53:04 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/26 19:54:10 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H

# include <pthread.h>
# include <stdlib.h>

typedef struct s_mutex
{
	pthread_mutex_t	*list[1000];
	int				i;
}					t_mutex;

void				clear_mutex(void);
int					init_mutex(pthread_mutex_t *mutex);

#endif