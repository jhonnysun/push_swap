/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstcreate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:01:47 by jlaisney          #+#    #+#             */
/*   Updated: 2023/04/20 22:44:26 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



t_stack	*ft_lstnew(void *content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
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

void	ft_lstadd_back(t_stack **list, t_stack *new)
{
	if (!new || !list)
		return ;
	if (ft_lstsize(*list) == 0)
		*list = new;
	else
		ft_lstlast(*list)->next = new;
}

int return_index(int *array, int content, len)
{
    int i;

    i = 0;
    while (i <= len)
    {
        if (content == array[i])
            return (i);
        i++;
    }
    return (-1)
}

void    set_index(t_stack **list, int *array, int len)
{
    int i;
    int j;
    t_stack *lst_tmp;

    lst_tmp = *list;
    j = 0;
    i = 0;
    while (lst_tmp)
    {
        lst_tmp->index = return_index(array, lst_tmp->content, len);
        lst_tmp = lst_tmp->next;        
    }
}




