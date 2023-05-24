/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:30:04 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/20 18:31:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int not_sorted(char **av, int size)
{
    int i;
    int j;

    j = size;
    i = 1;
    if (size == 1)
        return (1);
    while (i < size)
    {
        while(j > i)
        {
            if (ft_atoi(av[i]) > ft_atoi(av[j]))
            {
                //printf("array, i = %s\narray,j = %s\nj = %i\nsize = %i\n", av[i], av[j], j, size);
                return (0);
            }    
            j--;
        }
        i++;
        j = size - 1;
    }
	write(1, "is_sorted\n", 11);
    return (1);
}

int has_dup_or_char(char **av, int size)
{
    int i;
    int j;

    i = 1;
	j = i + 1;
	if (not_nbr(av[1]))
		return (1);
    while (i < size)
    {
        while (j < size)
        {
            if (ft_atoi(av[i]) == ft_atoi(av[j]))
                return (1);
            j++;
        }
        i++;
		if (not_nbr(av[i]))
			return (1);
        j = i + 1;
    }
    return (0);
}
