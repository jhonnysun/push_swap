/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@mail.abc>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:25:11 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/27 14:19:02 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int find_index(t_stack **stack, int index, int clinch)
{
	static int debug;
    t_stack *tmp;
    int     i;

    i = 0;
    tmp = *stack;
	debug++;
	printf("DEBUG == %i\n", debug);
    while (tmp && i < clinch)
    {
        if (tmp->index == (size_t)index)
        {
			if (debug == 2)
			{
				printf("Index of nb is%li\n index = %i\n", tmp->index, index);
				printf("we want rotate: %i roundsbecause the list is = \n", i);
				print_list(*stack);
				printf("\n");
				exit(1);
			}
			
			return (i);
		}
        i++;
        tmp = tmp->next;
    }
	if (debug == 2)
	{
		printf("Index of nb is%li\n index = %i\n", tmp->index, index);
		printf("we want rotate: %i rounds because the list is = \n", i);
		print_list(*stack);
		printf("\n");
		exit(1);
	}
    return (i);
}

/*
int find_chunck(int chuncksize, int last_chunck, int stacklen)
{
    int new_chunk;
    if (last_chunck == 0)
        new_chunk = chunksize;
    if ((last_chunck + chunksize) <= stacklen)
        new_chunk = last_chunck + chunksize;
    return (new_chunk);
}
*/