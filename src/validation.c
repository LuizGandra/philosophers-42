/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:54:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/26 20:22:52 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	validate_args(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		return (handle_error(E_INVALID_ARGS));
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (handle_error(E_INVALID_ARG));
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
