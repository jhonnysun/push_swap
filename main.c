/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:08:37 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/25 16:08:37 by jlaisney         ###   ########.fr       */
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
		return (0);
	}
	write(1, "\n", 2);
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
	
    //a = malloc(sizeof(t_stack));
	//b->next = NULL;
	b = NULL;
	a = NULL;
    stacklen = (ac - 1);
	//before anything is done do the parsing here : check dup, is sorted, is not number and only 2 numbers, and max arguments allowed, quoted or not use split
	if (check_edge(av, stacklen))
		return (1);
	tosort = create(ac, av);
	print_array(tosort, ac);
    a = fill_a(tosort, stacklen); 
	
    //sorted = to_sort(tosort, ac);
    //set_index(&a, sorted, stacklen);
	//pa_pb(&a, &b, 2);
	//pa_pb(&a, &b, 2);
    printf("hallo hier ist a\n");
	print_list(a);

	
	write(1, "\n\n", 2);
	
	//chuncksize = set_chuncksize(stacklen);
	if (stacklen == 2)
	{
		if (a->index > a->next->index)
			ft_sa(&a, 1);
	}
	else if (stacklen == 3)
		sort_three(&a);
	else if (stacklen == 4)
		sort_four(&a, &b);
	else if (stacklen == 5)
		sort_five(&a, &b);
	else
		radix_sort(a, b, stacklen);
    //print_list(b);
    printf("hallo hier ist a\n");
	print_list(a);
    return (0);
}