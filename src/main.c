/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:11:41 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/23 09:18:32 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	// TODO 1. Validate arguments
	if (validate_args(argc, argv) != 0)
		return (1);
	// TODO 2. Initialize rules
	if (init_rules(argc, argv) != 0)
		return (1);
	// TODO 3. Initialize philosophers
	// TODO 4. Initialize mutexes
	// TODO 5. Initialize tasks
	(void)argc;
	(void)argv;
	return (0);
}

