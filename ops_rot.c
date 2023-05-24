/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:30:01 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/21 10:35:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack *find_forelast(t_stack **stack)
{
    t_stack **tmp;
    
    tmp = stack;
    if ((*tmp)->next == NULL)
        return (*tmp);
    while ((*tmp)->next != NULL)
    {
        if ((*tmp)->next->next == NULL)
            return (*tmp);
        *tmp = (*tmp)->next;
    }
    return (*tmp);
}

static void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

static void ra_rb_printer(int mod, int flag)
{
    if (flag)
        return ;  
    if (mod == 1)
        write(1, "ra\n", 3);
    if (mod == 2)
        write(1, "rb\n", 3); 
}


static void rra_rrb_printer(int mod, int flag)
{
    if (flag)
        return ;  
    if (mod == 1)
        write(1, "rra\n", 3);
    if (mod == 2)
        write(1, "rrb\n", 3); 
}

void    ra_rb(t_stack **a, t_stack **b, int mod, int flag)
{    
    t_stack *tmp;
    t_stack **c;
    
    if (mod == 1)
        c = a;
    else if (mod == 2)
        c = b;
    if (mod < 3)
    {
        if ((*c)->next == NULL)
            return ;
        tmp = *c;
        *c = (*c)->next;
        ft_lstadd_back(c, tmp);
        ra_rb_printer(mod, flag);
        tmp->next = NULL;
    }
    if (mod == 3)
    {
        ra_rb(a, b, 1, 1);
        ra_rb(a, b, 2, 1);
        write(1, "rr\n", 3);
    }
}
/*
void    rra_rrb(t_stack **a,t_stack **b,int mod,int flag)
{
    t_stack *tmp;
    t_stack **c;
    
    if (mod == 1)
        c = a;
    else if (mod == 2)
        c = b;
    if (mod < 3)
    {
        tmp = ft_lstlast(*c);
        ft_lstadd_front(c, tmp);
        tmp = find_forelast(c);       
        tmp->next = NULL;
    }
    if (mod == 3)
    {
        rra_rrb(a, b, 1, 1);
        rra_rrb(a, b, 2, 1);
        write(1, "rrr\n", 3);
    }
}*/

void rra_rrb(t_stack **a, t_stack **b, int mod, int flag)
{
    t_stack *tmp;
    t_stack **c;
    
    if (mod == 1)
        c = a;
    else if (mod == 2)
        c = b;
    if (mod < 3 && *c != NULL) 
    { // check if stack is not empty
        
        tmp = *c;
        while (tmp->next != NULL && tmp->next->next != NULL) 
        {
            tmp = tmp->next;
        }
        if (tmp->next != NULL) 
        { // check if there is more than one element in the stack
            tmp->next->next = *c;
            *c = tmp->next;
            tmp->next = NULL;
            rra_rrb_printer(mod, flag);
        }
    }
    if (mod == 3)
    {
        
        if (mod == 3 && b == NULL)
        {
            rra_rrb(a, b, 1, 0);
            rra_rrb_printer(1, 0);  
        }
        else if (mod == 3 && a == NULL)
        {
            rra_rrb(a, b, 2, 0);
            rra_rrb_printer(2, 0);  
            
        }
        rra_rrb(a, b, 1, 1);
        rra_rrb(a, b, 2, 1);
        write(1, "rrr\n", 4);
    }
}
