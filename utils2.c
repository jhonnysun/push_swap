/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@mail.abc>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:25:11 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/27 16:06:24 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int find_index(t_stack **stack, int clinch, int index)
{
	static int debug;
    t_stack *tmp;
    int     i;

    i = 0;
    tmp = *stack;
	debug = 1000;
	//printf("DEBUG == %i\n", debug);
    while (tmp && i < clinch)
    {
        if ((int)tmp->index == index)
        {
			if (debug == 3)
			{
				printf("Index of nb is%li\nindex we search is= %i\n", tmp->index, index);
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
	if (debug == 3)
	{
		printf("Index of nb is%li\nindex we search is= %i\n", tmp->index, index);
		printf("1we want rotate: %i rounds because the list is = \n", 0);
		print_list(*stack);
		printf("\n");
		exit(1);
	}
    return (0);
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