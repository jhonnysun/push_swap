/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chuncks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:30:11 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/25 18:30:11 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int set_chuncksize(int elements)
{
    int chuncksize;

    if (elements <= 100)
        chuncksize = elements / 5 - 2;
    else
        chuncksize = elements / 10 - 2;
    return (chuncksize);
}


/*
int chunck_next(int chunksize, int max_elements)
{
    int chunk_start;
    int chunk_end;

    chunk_start = 1;
    chunk_end = chunksize;
    while (chunk_end <= max_elements)
    {
        check_direction(&a,max_elements, chunk_start, chunk_end);
        chunk_start = chunk_end + 1;
        chunk_end = chunk_end + chunksize;

    }
}

//somehow gotta implement a fix that will take care of 
int check_direction(t_stack **stack, int max_elements, int chuncksize, int chunk_end)
{
    int mid;
    int top;
    int bot;
    int iterator;
    int nextchunk;

    nextchunk = chunksize;
    iterator = 0;
    top = 0;
    bot = 0;
    mid = max_elements / 2;
    while (*stack)
    {
        if ((*stack)->index <= chuncksize && iterator <= mid)
            top++;
        if ((*stack)->index <= chuncksize && iterator >= mid)
            bot++;
        //now check how many more elements in which half and how far they are from an end for rotation
        stack = (*stack)->next;
        iterator++;
    }
    //this has to be in the calling function, every chunck hast to be given to make the trace fnc simpler
    if (chuncksize <= max_elements)
        chuncksize += chuncksize;
}

void    logic_calls()
{

}

t_positions first_last(t_stack **a, int chunckindex, int max_elements)
{
    int first;
    int last;
    int top;
    int bot;
    int mid;
    int iterator;
    int trigger_top;
    int trigger_bot;
    t_positions first_last;

    trigger_bot = 1;
    trigger_top = 1;
    iterator = 1;
    mid = max_elements / 2;
    while((*a)->next != NULL)
    {
        if ((*a)->index <= chunckindex && trigger_top == 1)
        {
            first_last->pos_first = iterator;
            trigger_top = 0;
        }
        if ((*a)->index <= chunckindex && trigger_top == 1)
        {
            first_last->pos_last = max_elements - iterator;
            trigger_bot = 0;
        }
        if ((*stack)->index <= chunckindex && iterator <= mid)
            top++;
        if ((*stack)->index <= chunckindex && iterator >= mid)
            bot++;
        a = (*a)->next;
        iterator++;
    }
    first_last.elem_top = top;
    first_last.elem_bot = bot;
    return(first_last);
}

t_positions top_bot(t_stack **a, int chunckindex, int max_elements)
{
    int top;
    int bot;
    int i;
    int mid;
    t_positions first_last;


    mid = max_elements / 2;
    i = 1;
    while ((*a)->next != NULL)
    {
        if (i <= mid && (*a)->index <= chunckindex)
            top++;
        if (i > mid && (*a)->index <= chunckindex)
            bot++;
        a = (*a)->next;
        i++;
    }
    first_last.elem_top = top;
    first_last.elem_bot = bot;
    return (first_last);
}

t_positions n_rot(t_stack **a, int chunkckindex, int max_elements)
{
    t_positions current_spread;
    int top;
    int bot;
    int n_rot_top;
    int n_rot_bot;
    int i;
    int mid;

    mid = max_elements / 2;
    i = 1;
    current_spread = top_bot(&a, chunkckindex, max_elements);
    top = current_spread.elem_top;
    bot = current_spread.elem_bot;
    while ((*a))
    {
        if (i <= mid && (*a)->index <= chunkckindex && top > 0)
        {
            current_spread.n_rot_top = i;
            top--;
        }
        if (i > mid && (*a)->index <= chunkckindex)
            current_spread.n_rot_bot = max_elements - i;
        i++;
        a = (*a)->next;
    }
    return (current_spread);
}

int check_direction(t_stack **a, int chunkindex, int max_elements)
{
    t_positions less_rot;

    less_rot = n_rot(&a,chunkindex, max_elements);
    if (less_rot.n_rot_top < less_rot.elem_bot)
        return (1);
    if (less_rot.n_rot_top == less_rot.elem_bot)
        return (1);
    if (less_rot.n_rot_top > less_rot.elem_bot)
        return (0);
}*/

// have to check something for more elements in one half and faster access