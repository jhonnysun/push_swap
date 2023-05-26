/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@mail.abc>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:25:11 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/26 14:12:15 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int find_index(t_stack **stack, int index)
{
    t_stack *tmp;
    int     i;

    i = 0;
    tmp = *stack;
    while (tmp)
    {
        if (tmp->index == (size_t)index)
            return (i);
        i++;
        tmp = tmp->next;
    }
    return (0);
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