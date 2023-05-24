/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:49:14 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/24 22:18:19 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    sub_three(t_stack **stack, int *n)
{
    t_stack *tmp;
    
    printf("inside\n");
    tmp = NULL;
    printf("OUTside\n");
    //321, 132
    if (n[0] > n[1] && n[1] > n[2])
    {
        sa_sb(stack, &tmp, 1, 1);
        rra_rrb(stack, &tmp, 1, 1);         
    }
    else if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
    {
        sa_sb(stack, &tmp, 1, 1);
        ra_rb(stack, &tmp, 1, 1);
    }   
}

void    sort_three(t_stack **stack)
{
    t_stack *tmp;
    int     n[3];
    int     i;
    
    tmp = *stack;
    i = 0;
    while (i <= 2)
    {
        n[i] = (*stack)->index;
        *stack = (*stack)->next;
        i++;
    }
    //312, 213, 231 
    if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
        ra_rb(stack, &tmp, 1, 1);       
    else if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
        sa_sb(stack, &tmp, 1, 1);
    else if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
        rra_rrb(stack, &tmp, 1, 1);
    else
        sub_three(stack, n); 
}

void    sort_four(t_stack **a, t_stack **b)
{
    push_min(a, b);
    sort_three(a);
    pa_pb(a, b, 2);
}

void    sort_five(t_stack **a, t_stack **b)
{
    push_min(a, b);
    push_min(a, b);
    sort_three(a);
    pa_pb(a, b, 2);
}

void    radix_sort(t_stack **a, t_stack **b, int stacklen)
{
    
}