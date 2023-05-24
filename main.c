/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:34:09 by marvin            #+#    #+#             */
/*   Updated: 2023/05/20 18:34:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <string.h>

static int	check_edge(char **av, int len)
{
	 if ((len + 1) <= 2 || has_dup_or_char(av, len))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (not_sorted(av, (len)))
	{
		write(1, "1\n", 2);
		return (0);
	}
	return (0);
}
int main(int ac, char **av)
{
    int     *tosort;
    int     *sorted;
    int     stacklen;
    t_stack *a;
	t_stack *b;
	int	chuncksize;
	
    a = malloc(sizeof(t_stack));
	//b->next = NULL;
	b = NULL;
    stacklen = (ac - 1);
	//before anything is done do the parsing here : check dup, is sorted, is not number and only 2 numbers, and max arguments allowed, quoted or not use split
	if (check_edge(av, stacklen))
		return (1);
	tosort = create(ac, av);
	print_array(sorted, ac);
    a = fill_a(tosort, stacklen, a); 
	
    //sorted = to_sort(tosort, ac);
    //set_index(&a, sorted, stacklen);
	//pa_pb(&a, &b, 2);
	//pa_pb(&a, &b, 2);
    print_list(a);
	
	write(1, "\n\n", 2);
	
	chuncksize = set_chuncksize(stacklen);
	if (stacklen == 2)
	{
		if (a->index > a->next->index)
			sa_sb(&a, &b, 1, 1);
	}
	else if (stacklen == 3)
		sort_three(&a);
	else if (stacklen == 4)
		sort_four(&a, &b);
	else if (stacklen == 5)
		sort_five(&a, &b);
	else
		radix_sort(a, b, stacklen);
    print_list(a);
    return (0);
}