/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugprints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:09:24 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/27 14:33:13 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    print_list(t_stack *list)
{
    printf("liste ======\n");
    while(list)
    {
        printf("list_index = %li   list_Content = %i\n", list->index, list->content);
        list = list->next;
    }
}

void	print_array(int *array, int ac)
{
	int	i;

	i = 0;
	while (i < (ac - 1))
	{
        printf("array_index = %i   array_Content = %i\n", i, array[i]);
		i++;
	}
}