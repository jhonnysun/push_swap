/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugprints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:09:24 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/20 19:38:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*void    ll_print_list(t_stack *a)
{
    t_stack *tmp;

    tmp = a;
    while (tmp)
    {
        ft_putnbr_fd(tmp->content, 1);
        write(1, "\n", 1);
        tmp = tmp->next;    
    } 
}*/

void    print_list(t_stack *list)
{
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
	while (i <= (ac - 2))
	{
        printf("array_index = %i   array_Content = %i\n", i, array[i]);
		i++;
	}
}