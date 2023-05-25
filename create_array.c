/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:30:00 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/25 18:30:00 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int *create(int ac, char **av)
{
    int *filled;
    int i;
    int j;

    j = 1;
    i = 0;
    filled = malloc(sizeof(int) * (ac - 1));
    while (j <= (ac - 1))
    {
        filled[i] = atoi(av[j]);
        i++;
        j++;
    }
	return (filled);
}

int *to_sort(int *sorted, int ac)
{
    int i;
    int j;
    int push;
    int tmp;

    i = 0;    
    j = ac - 2;
    while (i < j)
    {
        // this is for the last 2 numbers in the array
        while(j > i)
        {
            if (sorted[i] > sorted[j])
            {
                tmp = sorted[j];
				sorted[j] = sorted[i];
                sorted[i] = tmp;
            }
            j--;
        }
        //sorted[i] = tmp;
        i++;
        j = ac - 2;
    }
    return (sorted);
}

int is_sorted(int *array, int size)
{
    int i;
    int j;

    j = size - 1;
    i = 0;
    if (size == 1)
        return (1);
    while (i < size)
    {
        while(j > i)
        {
            if (array[i] > array[j])
            {
                //printf("array, i = %i\narray,j = %i\nj = %i\nsize = %i\n", array[i], array[j], j, size);
                return (1);
            }    
            j--;
        }
        i++;
        j = size - 1;
    }
    return (0);
}

int return_index(int *array, int content, int len)
{
    int i;

    i = 0;
    while (i <= len)
    {
        if (content == array[i])
            return (i + 1);
        i++;
    }
    return (-1);
}

void    set_index(t_stack **list, int *array, int len)
{
    int i;
    int j;
    t_stack *lst_tmp;

    lst_tmp = *list;
    j = 0;
    i = 0;
    while (lst_tmp)
    {
        lst_tmp->index = return_index(array, lst_tmp->content, len);
        lst_tmp = lst_tmp->next;        
    }
}