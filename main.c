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
	
	b = NULL;
	a = NULL;
    stacklen = (ac - 1);
	if (check_edge(av, stacklen))
		return (1);
	tosort = create(ac, av);
    a = fill_a(tosort, stacklen);
	//print_list(a);
	//stacklen = ft_lstsize(a);
	//printf("stacklen = %i\n", stacklen);
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
	ft_free(a, b, stacklen, sorted);
    return (0);
}