/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:51:40 by marvin            #+#    #+#             */
/*   Updated: 2023/05/20 17:51:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
    list->index = 0;
	list->content = content;
	list->next = NULL;
	return (list);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_stack **list, t_stack *new)
{
	if (!new || !list)
		return ;
	if (ft_lstsize(*list) == 0)
		*list = new;
	else
		ft_lstlast(*list)->next = new;
}

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
	tmp->next = NULL;
    return (a);
}