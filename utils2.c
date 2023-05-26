/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:25:11 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/26 21:19:08 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bt find_index(t_stack **stack, int index, int max)
{
    t_stack *tmp;
    t_bt    rtn;
    int     i;
    int     stacklen;

    i = 0;
    stacklen = ft_lstsize(*stack);
    memset(&rtn, -1, 3);
    tmp = *stack;
    while (tmp)
    {
        if (tmp->index == (size_t)index && rtn.bot == -1)
            rtn.bot = i;
        if (tmp->index <= (size_t)max)
            rtn.top = i;  
        i++;
        tmp = tmp->next;
    }
    rtn.top = stacklen - rtn.top;
    if (rtn.bot < rtn.top)
        rtn.direction = ROTATE;
    else
        rtn.direction = REVERSE;
    return (rtn);
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