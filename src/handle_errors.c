/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:33:00 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/23 08:33:00 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int handle_error(const char *error_message, const int error_code)
{
		write(2, error_message, ft_strlen(error_message));
		return (error_code);
}