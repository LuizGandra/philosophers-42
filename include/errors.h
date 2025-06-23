/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:06:01 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/23 09:22:42 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

// COLORS
# define C_RED "\033[1;31m"
# define C_RESET "\033[0m"

// ERRORS
# define ERROR_INVALID_ARGS C_RED"Invalid number of arguments. Expected 4 or 5 arguments.\n"C_RESET

// ? + sign is valid? if no, change to "Please enter unsigned numeric values."
# define ERROR_INVALID_ARG_TYPE C_RED"Invalid argument type. Please enter positive numeric values.\n"C_RESET

# define ERROR_INVALID_NUM_PHILO C_RED"Invalid number of philosophers. Must be at least 1.\n"C_RESET

#endif
