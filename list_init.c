/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:08:14 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/25 16:08:14 by jlaisney         ###   ########.fr       */
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
	if (lst == NULL)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_stack **list, t_stack *new)
{
	if (!new)
		return ;
	if (!(*list) || ft_lstsize(*list) == 0)
		*list = new;
	else
		ft_lstlast(*list)->next = new;
}

t_stack *fill_a(int *array, int len)
{
    int     i;
    t_stack *tmp;
    t_stack *rtn;

    
    i = 0;
	rtn = NULL;
	printf("LEN = %i\n", len);
	tmp = ft_lstnew(array[i++]);
	ft_lstadd_back(&rtn, tmp);	
	printf("ERROR\n");
    while (i < len)
    {
		printf("i = %i\n", i);
		tmp = ft_lstnew(array[i++]);
		ft_lstadd_back(&rtn, tmp);
		if (i == len + 1)
		{
			ft_lstadd_back(&rtn, NULL);
			break ;
		}
    }
    return (rtn);
}