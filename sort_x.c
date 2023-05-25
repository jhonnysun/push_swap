/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:49:14 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/25 16:03:31 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    sub_three(t_stack **stack, int *n)
{
    t_stack *tmp;
    
    printf("inside\n");
    printf("OUTside\n");
    //321, 132
    if (n[0] > n[1] && n[1] > n[2])
    {
        ft_sa(stack, 1);
        reverse_rra(stack, 1);         
    }
    else if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
    {
        ft_sa(stack, 1);
        ft_ra(stack, 1);
    }   
}

void    sort_three(t_stack **stack)
{
    t_stack *tmp;
    int     n[3];
    int     i;
    
    tmp = NULL;
    i = 0;
    while (i <= 2)
    {
        printf("i in sort_3 = %i\n", i);
        n[i] = (*stack)->index;
        *stack = (*stack)->next;
        i++;
    }
    //312, 213, 231 
    if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
        ft_ra(stack, 1);       
    else if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
        ft_sa(stack, 1);
    else if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
        reverse_rra(stack, 1);
    else
        sub_three(stack, n); 
}

void    sort_four(t_stack **a, t_stack **b)
{
    push_min(a, b);
    sort_three(a);
    pb_pa(a, b, 2);
}

void    sort_five(t_stack **a, t_stack **b)
{
    push_min(a, b);
    push_min(a, b);
    sort_three(a);
    pb_pa(a, b, 2);
}

void    radix_sort(t_stack **a, t_stack **b, int stacklen)
{
    
}