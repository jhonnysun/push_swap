/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:49:14 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/26 00:01:57 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    sub_three(t_stack **stack, int *n)
{
    t_stack *tmp;
    if (VERBOSE)
        printf("sub_three\n");
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
    
    tmp = *stack;
    i = 0;
    while (i <= 2)
    {
        if (VERBOSE)
            printf("i in sort_3 = %i\n", i);
        n[i] = tmp->content;
        tmp = tmp->next;
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
    //printf("halloooooo\n");
    push_min(a, b);
	pb_pa(a, b, 2);
    sort_three(a);
	pb_pa(b, a, 1);
    //printf("head b = %i\nsecond b = %i\n", (*b)->index);
    /*if ((*b)->index > (*b)->next->index)
    {
    	pb_pa(b, a, 1);
    	pb_pa(b, a, 1);
        
    }
    else
    {
        ft_sb(b,1);
     	pb_pa(b, a, 1);
    	pb_pa(b, a, 1);       
    }*/
}

void    sort_five(t_stack **a, t_stack **b)
{
    push_min(a, b);
	pb_pa(a, b, 2); 
    push_min(a, b);
	pb_pa(a, b, 2);

    sort_three(a);
    pb_pa(b, a, 1);
    pb_pa(b, a, 1);

}

//mod 1 = a / mod 2 = b
void    n_rotations(t_stack **stack,int mod, int rounds)
{
    while (rounds > 0)
    {
        ft_rb(stack, 1);
        rounds--;
    }
    
}

static void push_back(t_stack **a, t_stack **b, int i, int max)
{
    int rounds;
    
    while (*b)
    {
        while (i > 0 && i >= max)
        {
            rounds = find_index(b, i);
            n_rotations(b, 2, rounds);
            pb_pa(b, a, 1);
            i--;
        }
        max -= 5;
    }
}

void    radix_sort(t_stack **a, t_stack **b, int stacklen)
{
    int i;
    int max;
    int size;

    i = 1;
    max = 0;
    //print_list(*a);
    while (*a)
    {
        max += set_chuncksize(stacklen);
	    //printf("1max = %i\n", max);
        while (i <= max && *a)
        {
	        //printf("2222222\n");
            if (*a == NULL)
                break ;
            if ((*a)->index <= max)
            {
                pb_pa(a, b, 2);
                i++;
            }
            else
            {
                //optimierung decide direction
                ft_ra(a, 1);
                
            }   
        }
    }
    push_back(a, b, i - 1, max);
}