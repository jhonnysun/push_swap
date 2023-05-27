/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:25:11 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/27 15:03:37 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int find_index_b(t_stack **stack, int index, int chunksize)
{
    t_stack *tmp;
    int     i;

    i = 0;
    tmp = *stack;
    while (tmp && i < chunksize)
    {
        if ((*stack)->index == (size_t)index)
        {
            printf("index = %i\n", index);
            return (i);
            
        }    
        i++;
        tmp = tmp->next;
    }
    return (i);
}

void    ft_free(t_stack *a, t_stack *b, int stacklen, int *sorted)
{
	t_stack *tmp;
    
    if (a)
	{
		while (a)
		{
			tmp = a->next;
			free(a);
			a = tmp;
		}
	}
	if (b)
	{
		while (b)
		{
			tmp = b->next;
			free(a);
			b = tmp;
		}	
	}	
	if (stacklen)
		free(sorted);
}

int size_start_end(int chunksize, int stacklen_a)
{
    int max_index;

    max_index = 0;
    if (max_index >= stacklen_a)
        return (stacklen_a);
    max_index += chunksize;
    return (max_index);
}

/*
int find_chunck(int chuncksize, int last_chunck, int stacklen)
{
    int new_chunk;
    if (last_chunck == 0)
        new_chunk = chunksize;
    if ((last_chunck + chunksize) <= stacklen)
        new_chunk = last_chunck + chunksize;
    return (new_chunk);
}
*/

