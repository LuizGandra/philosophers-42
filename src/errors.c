/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizc <luizc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:52:21 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/07/07 08:27:12 by luizc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_error(char *error_msg, t_error_options option)
{
	const char	*help_msg = C_WHITE "\nUsage: ./philosophers\n"
		"	number_of_philosophers\n"
		"	time_to_die\n"
		"	time_to_eat\n"
		"	time_to_sleep\n"
		"	[number_of_times_each_philosopher_must_eat]\n\n"
		"All arguments must be unsigned integers.\n\n" C_RESET;

	if (option == CLEAN)
	{
		ft_clear_heap();
		clear_mutex();
	}
	else if (option == SHOW_HELP)
	{
		write(2, help_msg, ft_strlen(help_msg));
		return (EXIT_FAILURE);
	}
	write(2, error_msg, ft_strlen(error_msg));
	return (EXIT_FAILURE);
}
