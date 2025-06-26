/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/06/26 19:50:58 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/26 19:50:58 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CALLOC_H
# define FT_CALLOC_H

# define MAX_SIZE 1024

# include <stdint.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_heap
{
	void	*list[MAX_SIZE];
	int		i;
}			t_heap;

void	*ft_calloc(size_t size);
void	ft_clear_heap(void);

#endif
