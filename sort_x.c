/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@mail.abc>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:49:14 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/27 17:29:54 by jjesberg         ###   ########.fr       */
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
void    n_rotations(t_stack **a, t_stack **b, int rounds)
{
	
}

static void push_back(t_stack **a, t_stack **b, int i, int max)
{
	//TODOO push back to a 
}

void    radix_sort(t_stack **a, t_stack **b, int stacklen)
{
    size_t i;
    size_t max;

    i = 0;
	max = set_chuncksize(stacklen);
	printf("chunksize = %li\n", max);
    while (*a)
    {
		//TODOO make a good b stack with chunks...
    }
	print_list(*b);
	exit(1);
    push_back(a, b, i, max);
}