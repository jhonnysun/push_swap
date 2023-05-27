/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_optimize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@mail.abc>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:05:47 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/27 13:46:36 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_bt find_direction(t_stack *stack, int max)
{
    t_bt    rtn;
    t_stack     *tmp;
    int         i;
    int         stacklen;

    i = 0;
    memset(&rtn, -1, 3);
    tmp = stack;
    stacklen = ft_lstsize(stack);
    while(tmp)
    {
        if ((int)tmp->index <= max && rtn.bot == -1)
            rtn.bot = i;
        else if ((int)tmp->index <= max)
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

void    use_direction(t_stack **a,t_stack **b, int max)
{
    t_bt rounds;

	(void)b;
    rounds = find_direction(*a, max);
    if (rounds.direction == REVERSE)
    {
        while (!((*a)->index <= (size_t)max))
        {    
            //if ( *b && (*b)->next != NULL && (*b)->next != NULL)
               // check_swap(a, b);
            reverse_rra(a, 1);
        }
    }
    else if (rounds.direction == ROTATE)
    {
        while ((!((*a)->index <= (size_t)max)))
        {
            //if ( *b && (*b)->next != NULL && (*b)->next != NULL)
             //   check_swap(a, b);
            ft_ra(a, 1);
        }
    }
}

void    check_swap(t_stack **a, t_stack **b)
{
    if ((*a)->index > (*a)->next->index \
    && (*b)->index < (*b)->next->index)
    {
        ft_ss(a, b);   
    }
    else if ((*a)->index > (*a)->next->index)
    {
        ft_sa(a, 1);
    }
    else if ((*b)->index < (*b)->next->index)
        ft_sb(b, 1);
    
}

/*
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