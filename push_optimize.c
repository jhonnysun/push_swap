/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_optimize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@mail.abc>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:05:47 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/27 17:30:49 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int find_direction(t_stack **a, t_stack **b, int max)
{
	use_direction(a, b, max);
}

void    use_direction(t_stack **a,t_stack **b, int max)
{
	 //TODOO!!
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