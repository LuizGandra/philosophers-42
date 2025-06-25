/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:18:52 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/06/25 09:18:52 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_calloc.h"

static t_heap	*get_heap(void)
{
	static t_heap heap;

	return (&heap);
}

void	*ft_calloc(size_t size)
{
	t_heap	*heap;
	void	*ptr;

	heap = get_heap();
	if (size == 0 || size > SIZE_MAX - sizeof(t_heap))
		return (NULL);
	ptr = malloc(size);
	memset(ptr, 0, size);
	heap->list[heap->i] = ptr;
	heap->i++;
	return (ptr);
}

void	ft_clear_mem(void)
{
	t_heap	*heap;

	heap = get_heap();
	while (heap->i > 0)
	{
		heap->i--;
		free(heap->list[heap->i]);
		heap->list[heap->i] = NULL;
	}
}
