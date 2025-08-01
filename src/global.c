/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:56:14 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/26 21:04:18 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

t_aux_mutexes	*get_aux_mutexes(void)
{
	static t_aux_mutexes	aux_mutexes;

	return (&aux_mutexes);
}
