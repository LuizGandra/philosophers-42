/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:52:21 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/27 21:50:44 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_error(char *error_msg, int clear)
{
	write(2, error_msg, ft_strlen(error_msg));
	if (clear)
	{
		ft_clear_heap();
		clear_mutex();
	}
	return (EXIT_FAILURE);
}
