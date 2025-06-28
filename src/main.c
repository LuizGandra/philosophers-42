/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:11:41 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/28 12:46:15 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	if (validate_args(argc, argv) != 0)
		return (EXIT_FAILURE);
	if (init_data(argc, argv) != 0)
		return (EXIT_FAILURE);
	if (init_philosopher() != 0)
		return (EXIT_FAILURE);
	if (init_aux_mutexes() != 0)
		return (EXIT_FAILURE);
	if (init_task() != 0)
		return (EXIT_FAILURE);
	ft_clear_heap();
	clear_mutex();
	return (EXIT_SUCCESS);
}
