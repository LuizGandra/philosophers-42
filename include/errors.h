/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:59:29 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/28 13:06:22 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

// COLORS
# define C_RED "\033[1;31m"
# define C_WHITE "\033[1;37m"
# define C_RESET "\033[0m"

typedef enum e_error_options
{
	DEFAULT,
	CLEAN,
	SHOW_HELP
}					t_error_options;

// ERRORS
# define E_INVALID_ARGC "\033[1;31mExpected 4 or 5 arguments.\n\033[0m"
# define E_INVALID_ARGS "\033[1;31mEnter only unsigned numeric values.\n\033[0m"
# define E_INVALID_PHILOS "\033[1;31mMust be at least 1 philosopher.\n\033[0m"
# define E_MUTEX_INIT "\033[1;31mMutex initialization failed.\n\033[0m"
# define E_THREAD_INIT "\033[1;31mThread initialization failed.\n\033[0m"

// HANDLE ERRORS
int					handle_error(char *error_message, t_error_options option);

#endif
