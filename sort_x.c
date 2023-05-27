/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:49:14 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/26 22:56:59 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*321, 132*/
void    sub_three(t_stack **stack, int *n)
{
    if (VERBOSE)
        printf("sub_three\n");
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

/*312, 213, 231*/ 
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
	pb_pa(a, b, 2);
    sort_three(a);
	pb_pa(b, a, 1);
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
void    n_rotations(t_stack **a,t_stack **b, int rounds)
{
    int rotback;

    rotback = rounds - 1;
    while (rounds > 0)
    {
        ft_rb(a, 1);
        rounds--;
    }
    pb_pa(b, a, 1);
    while (rotback > 0)
    {
        reverse_rrb(b, 1);
        rotback--;
    }
}

static void push_back(t_stack **a, t_stack **b, int i, int test)
{
    int rounds;
    int chunksize;
    (void)test;
    
    while (*b)
    {
        chunksize = set_chuncksize(i);
        while (chunksize)
        {
            rounds = find_index_b(b, i, chunksize);
            n_rotations(a, b, rounds);
            chunksize--;            
            
        }
       
        
    }
}

void    radix_sort(t_stack **a, t_stack **b, int stacklen)
{
    size_t i;
    size_t max;
    int test;

    i = 0;
	max = 0;
    while (*a)
    {
        test = 0;
		max += set_chuncksize(stacklen);
        while (i <= max && *a)
        {
			
            if (*a == NULL)
                break ;
            if ((*a)->index <= max)
            {
                pb_pa(a, b, 2);
                i++;
            }
            else
            {
                
                use_direction(a, b, max);                
            }
            test++;   
        }
    }
    printf("test = %i\n", test);
    printf("chunk = %i\n", set_chuncksize(stacklen));
    push_back(a, b, i, test);
}