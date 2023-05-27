/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:49:39 by marvin            #+#    #+#             */
/*   Updated: 2023/05/27 00:49:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
int find_shortest_push_a(t_stack ** a, int stacklen, int chunksize)
{
    int i;
    int first;
    int last;
    int trigger;
    int max_member;

    max_member = 0;
    trigger = 1;
    i = 0;
    while (*a)
    {
        if ((*a)->index <= chunksize)
        {
            if (trigger)
            {
            first = i;
            trigger = 0;
            }
            max_member++;
        }
        if (max_member ==  chunksize)
            last = i;   
        i++;
        *a = (*a)->next;
    }
    if (first < stacklen - last)
        return (1);
    else
        return (0);
}
*/

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

int find_first_a(t_stack **a, int max_index)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = (*a);
    while ((tmp))
    {
        if (tmp->index <= (size_t)max_index)
            return (i);
        i++;
        tmp = tmp->next;
    }
    return (0);
}

int find_last_a(t_stack **a, int max_index, int chuncksize)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = (*a);
    while (tmp)
    {
        if (tmp->index <= (size_t)max_index)
        {
            //maybe need chuncksize - 1 here
            if (chuncksize == 0)
                return (i);
            chuncksize--;
        }
        i++;
        tmp = tmp->next;
    }
    return (0);
}

/*return 1 = rotate & return 2 = reverse*/
int find_direction_a(t_stack **a, int max_index, int chuncksize)
{
    int first;
    int last;
    int stacklen;

    stacklen = ft_lstsize(*a);
    first = find_first_a(a, max_index);
    last = find_last_a(a, max_index, chuncksize);
    printf("first = %i\n", first);
    printf("last = %i\n", last);
    print_list(*a);
    //exit(123);
    if (first < stacklen - last)
        return (1);
    else
        return (0);
}

int push_shortest(t_stack **a, t_stack **b, int max_index, int chuncksize)
{
    int stacklen;
    int tmp_chunck;
    int trigger;
    static int check;

    tmp_chunck = chuncksize;
    stacklen = ft_lstsize(*a);
 //   if (find_direction(a, max_index, chuncksize))            evtl braucht man dass nur einmal abchecken, weil nach einer rotation der abstand am stackende wächst
        while (*a)
        {
            trigger = find_direction_a(a, max_index, chuncksize);

            while (trigger && (*a)->index > (size_t)max_index)
                ft_ra(a, 1);
            while (!trigger && (*a)->index > (size_t)max_index)
                reverse_rra(a, 1);
            while (*a && (*a)->index <= (size_t)max_index)
            {
                if (check > 1)
                {    
                    printf("to push = %i\n", (*a)->content);
                    exit(123);
                }
                pb_pa(a, b, 2);
                check++;
                tmp_chunck--;
                stacklen--;
                if (tmp_chunck == 0)
                    return (stacklen);
            }


        }
    // in dem fall wäre hier das else und ein zweiter while loop, eventuel sollte stacklen zurückgeben werden um einen neuen chunck dynamisch zu errechnen 
    return (0);
}


/*mod 1 = a / mod 2 = b
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
*/

/*static void push_back(t_stack **a, t_stack **b, int stacklen_b, int test)
{
    int rounds;
    int chunksize;
    (void)test;
    
    while (*b)
    {
        chunksize = set_chuncksize(stacklen_b);
        while (chunksize)
        {
            rounds = find_index_b(b, stacklen_b, chunksize);
            n_rotations(a, b, rounds);
            chunksize--;            
            
        }
       
        
    }
}
*/

void    radix_sort(t_stack **a, t_stack **b, int stacklen_a)
{
    //int     stacklen_tmp;
    //int     stacklen_b;
    int     chuncksize;
    int     max_index;
    //int     test;

    //stacklen_b = 0;
    //stacklen_tmp = stacklen_a;
	chuncksize = set_chuncksize(stacklen_a);
    printf("chuncksize = %i\n", chuncksize);
    while (*a)
    {
        //printf("inside radix\n");
        //chuncksize = set_chuncksize(stacklen); hier kann man schon die dynamik regeln das increasen durch += halte ich für falsch zu undurchsichtig
        //man updatet am besten stacklen und bekommt so immer andere chunks, diese sollte man eventuell alle in einem struct speichern
		chuncksize += set_chuncksize(stacklen_a);
        max_index = size_start_end(chuncksize, stacklen_a);
        //printf("chuncksize = %i\n", chuncksize);
        //printf("max_index = %i\n", max_index);

        //exit(123);
        while (chuncksize <= stacklen_a)
        {	
            //printf("0000000000000000000\n");
            //exit(123);
            if (*a == NULL)
                break ;
            stacklen_a = push_shortest(a, b, max_index, chuncksize);
            //stacklen_b = stacklen_tmp - stacklen_a;               
        }
    }
    //push_back(a, b, stacklen_b, test);
    print_list(*b);
    print_list(*a);
}

