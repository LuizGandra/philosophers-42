/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:27:06 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/25 09:27:06 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CALLOC_H
# define FT_CALLOC_H

# define MAX_SIZE 1024

# include <stdlib.h>
# include <string.h>
# include <stdint.h>

typedef struct s_heap
{
	void	*list[MAX_SIZE];
	int		i;
}	t_heap;

void *ft_calloc(size_t size);
void ft_clear_mem(void);

#endif
