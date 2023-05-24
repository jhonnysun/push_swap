/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:30:47 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/24 20:39:33 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "pushswap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top oDo nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top oDo nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.

*/
static void sa_sb_printer(int mod, int flag)
{
    if (flag)
        return ;  
    if (mod == 1)
        write(1, "sa\n", 3);
    if (mod == 2)
        write(1, "sb\n", 3); 
}

/*
mod 1 & flag 1 = swap a and print sa
mod 2 & flag 1 = swap b and print sb
mod 3 & flag 0 = swap a & b and print ss
*/
void    sa_sb(t_stack **a, t_stack **b, int mod, int flag)
{
    t_stack *tmp;
    t_stack **c;
    
    if (mod == 1)
        c = a;
    else if (mod == 2)
        c = b;
    if ((*c || (*c)->next != NULL) && mod < 3)
    {
        tmp = (*c)->next;
        (*c)->next = tmp->next;
        tmp->next = *c;
        *c = tmp;
        sa_sb_printer(mod, flag);
    }
    if (mod == 3)
    {
        sa_sb(a, b, 1, 1);
        sa_sb(a, b, 2, 1);
        write(1, "ss\n", 3);
    }
}

/*
mod 1 = b is src
mod 2 = a is src
this function needs that b was set to NULL befoer
*/
void    pa_pb(t_stack **src, t_stack **dest, int mod)
{
    t_stack *tmp;

    if (src)
    {
        tmp = (*src)->next;
        (*src)->next = *dest;
        *dest = *src;
        *src = tmp;
        if (mod == 1)
            write(1, "pa\n", 3);
        if (mod == 2)
            write(1, "pb\n", 3);    
    }        
}

