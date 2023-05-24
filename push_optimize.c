/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_optimize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:05:47 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/23 19:48:39 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    check_swap(t_stack **a, t_stack **b, int searchindex)
{
    if ((*b)->next != NULL && )
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