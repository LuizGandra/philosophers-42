/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:11:41 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/26 20:46:00 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	// * 1. Validate arguments
	if (validate_args(argc, argv) != 0)
		return (EXIT_FAILURE);
	// * 2. Initialize data
	if (init_data(argc, argv) != 0)
		return (EXIT_FAILURE);
	// * 3. Initialize philosophers
	if (init_philosopher() != 0)
		return (EXIT_FAILURE);
	// * 4. Initialize auxiliar mutexes
	if (init_aux_mutexes() != 0)
		return (EXIT_FAILURE);
	// * 5. Initialize tasks
	if (init_task() != 0)
		return (EXIT_FAILURE);
	// TODO create exit function
	ft_clear_heap();
	clear_mutex();
	return (EXIT_SUCCESS);
}
