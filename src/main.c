/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:11:41 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/25 09:31:20 by lcosta-g         ###   ########.fr       */
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
	// TODO 4. Initialize auxiliar mutexes
	// TODO 5. Initialize tasks
	return (EXIT_SUCCESS);
}

