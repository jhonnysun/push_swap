/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_quoted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:29:24 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/07 22:42:29 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack *fill_a(int *array, int len, t_stack *a)
{
    int     i;
    t_stack *tmp;
    
    tmp = NULL;
    i = 0;
    while (i < len)
    {
        tmp = ft_lstnew(array[i]);
        ft_lstadd_back(&a, tmp);
        i++;
    }
    return (a);
}

char **fromsplit(char *av[1])

int *convert_arr(char **splited, int size)
{
    int i;
    int j;
    int k;
    int *new;
    
    i = 0;
    j = 0;
    k = 0;
    
    while (splited[i] <= size)
    {
        new = ft_atoi(splited[i]);
        i++;
    }
    return (new);
}

// need wordcount at the beginning to determine the size of the array
// or after split i can count the size of the array

int elem_count(char **array)
{
    int i;
    
    i = 0;
    while (*array[i] != '\0')
        i++;
    return (i);
}

t_stack *list_quote(char **av)
{
    t_stack *list;
    char    **fromsplit;
    int     size;
    int     *singl_arr;
    t_stack *a;
    
    a = NULL;
    fromsplit = ft_split(av[1]);
    size = elem_count(fromsplit);
    singl_arr = convert_arr(fromsplit);
    list = fill_a(singl_arr, size, a);
    return (list);    
}

