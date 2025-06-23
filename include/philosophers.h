/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:06:01 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/23 09:23:52 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "errors.h"

# include <unistd.h>
# include <stdio.h>

typedef struct s_rules
{
	int	num_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_meals;
	int finished;
}	t_rules;

// VALIDATION
int	validate_args(int argc, char *argv[]);

// INIT
int	init_rules(int argc, char *argv[]);

// HANDLE ERRORS
int handle_error(const char *error_message, const int error_code);

// GLOBALS
t_rules *get_rules(void);

// UTILS
int	ft_strlen(const char *str);
int	ft_atoi(const char *str);

#endif
