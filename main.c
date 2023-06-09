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

int	check_edge(char **av, int len)
{
	 if ((len + 1) <= 2 || has_dup_or_char(av, len))
	{
		return (1);
	}
	if (not_sorted(av, (len)))
	{
		return (1);
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
	t_stack *tmp;
	
	b = NULL;
	a = NULL;
    stacklen = (ac - 1);
	//before anything is done do the parsing here : check dup, is sorted, is not number and only 2 numbers, and max arguments allowed, quoted or not use split
	if (check_edge(av, stacklen))
		return (1);
	tosort = create(ac, av);
	
    a = fill_a(tosort, stacklen); 
    sorted = to_sort(tosort, ac);

    set_index(&a, sorted, stacklen);

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
		radix_sort(&a, &b, stacklen);

	printf("HI\n");
	print_list(a);
	//TODOO do clean function
	if (a)
	{
		while (a)
		{
			tmp = a->next;
			free(a);
			a = tmp;
		}
	}
	if (b)
	{
		while (b)
		{
			tmp = b->next;
			free(a);
			b = tmp;
		}	
	}	
	if (stacklen)
		free(sorted);

    return (0);
}