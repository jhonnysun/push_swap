/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:11:14 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/25 18:40:13 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void    ft_ra(t_stack **a, int print)
{
    t_stack *tmp;
    
    if (!(*a) || (*a)->next == NULL)
            return ;
        tmp = (*a)->next;
        (*a)->next = NULL;
        ft_lstadd_back(&tmp, *a);
        *a = tmp;
        if (print == 1)
            write(1, "ra\n", 3);
}

void    ft_rb(t_stack **b, int print)
{
    t_stack *tmp;
    
    if ((*b)->next == NULL)
            return ;
        tmp = (*b)->next;
        (*b)->next = NULL;
        ft_lstadd_back(&tmp, *b);
        *b = tmp;
        if (print == 1)
            write(1, "rb\n", 3);
}

void    rotate_rr(t_stack **a, t_stack **b)
{
    ft_ra(a, 0);
    ft_rb(b, 0);
    write(1, "rr\n", 3);
}

void    reverse_rra(t_stack **a, int print)
{
    t_stack *tmp;
    t_stack *new;

    if ((*a)->next != NULL)
    {
        tmp = ft_lstlast(*a);
        new = ft_lstnew(tmp->content);
        tmp = *a;
        while (tmp->next)
        {
            if (!tmp->next->next)
            {
                free(tmp->next);
                tmp->next = NULL;
            }
            else
                tmp = tmp->next;
        }
        ft_lstadd_back(&new, *a);
        *a = new;
        if (print == 1)
            write(1, "rra\n", 4);
    }
}

void    reverse_rrb(t_stack **b, int print)
{
    t_stack *tmp;
    t_stack *new;

    if ((*b)->next != NULL)
    {
        tmp = ft_lstlast(*b);
        new = ft_lstnew(tmp->content);
        tmp = *b;
        while (tmp->next)
        {
            if (!tmp->next->next)
            {
                free(tmp->next);
                tmp->next = NULL;
            }
            else
                tmp = tmp->next;
        }
        ft_lstadd_back(&new, *b);
        *b = new;
        if (print == 1)
            write(1, "rrb\n", 4);
    }
}

void    reverse_rrr(t_stack **a, t_stack **b)
{
    reverse_rra(a, 0);
    reverse_rrb(b, 0);
    write(1, "rrr\n", 4);
}
