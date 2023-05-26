/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_optimize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:05:47 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/26 18:13:28 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* return (1) = reverse rotate & 0 = rotate */
int find_direction(t_stack *stack, int max)
{
    int     top;
    int     bot;
    t_stack *tmp;
    int     i;
    int     stacklen;

    i = 1;
    tmp = stack;
    top = 1;
    bot = -1;
    while(tmp)
    {
        if ((int)tmp->index < max && bot == -1)
            bot = i;
        else if ((int)tmp->index <= max)
            top = i;
        i++;
        tmp = tmp->next; 
    }
    stacklen = ft_lstsize(stack);
    
    if (stacklen - top < bot)
        return (1);
    return (0);
}

void    use_direction(t_stack **stack, int max)
{
    if (find_direction(*stack, max))
        reverse_rra(stack, 1);
    else
        ft_ra(stack, 1);
}
/*
void    check_swap(t_stack **a, t_stack **b, int searchindex)
{
    if ((*b)->next != NULL && (*b)->next != NULL)
    {
        
    }
}


t_stack find_push(t_stack **a, int ac)
{
    int max_elements;
    int chuncksize;
    int indexstart;
    int indexend;
    int n_chunck;
    int direction;
    int i;
    
    indexend = chuncksize;
    indexstart = 1;
    direction = n_rot(&a, chuncksize, max_elements);
    max_elements = ac - 1;
    chuncksize = set_chuncksize(max_elements);
    while (indexend <= max_elements)
    {
        check_swap(&a, &b, indexend);
        indexstart = indexend + 1;
        indexend += chuncksize;
    }
    
}
*/