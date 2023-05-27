/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@mail.abc>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:25:11 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/27 13:40:32 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int find_index(t_stack **stack, int index)
{
    t_stack *tmp;
    int    	round;
    int     i;

    i = 0;
	round = 0;
    tmp = *stack;
    while (tmp)
    {
        if (tmp->index == (size_t)index)
        {
			return (i);
		}
        i++;
        tmp = tmp->next;
    }
	printf("we want rotate %i round \n", round);
    return (round);
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