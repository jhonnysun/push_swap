/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@mail.abc>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:30:22 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/26 14:09:53 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    ft_sa(t_stack **a, int print)
{
    t_stack *tmp;
      
    if (*a && (*a)->next != NULL)
    {
        tmp = (*a)->next;
        (*a)->next = tmp->next;
        tmp->next = *a;
        *a = tmp;
        if (print == 1)
            write(1, "sa\n", 3);
    }
    //print_list(*a);
}

void    ft_sb(t_stack **b, int print)
{
      t_stack *tmp;
      
      if (*b && (*b)->next != NULL)
    {        
        tmp = (*b)->next;
        (*b)->next = tmp->next;
        tmp->next = *b;
        *b = tmp;
        if (print == 1)
            write(1, "sb\n", 3);
    }
}

void    ft_ss(t_stack **a, t_stack **b)
{
    ft_sa(a, 0);
    ft_sb(b, 0);
    write(1, "ss\n", 3);
}

/* mod = 1 push to a
   mod = 2 push to b  */
void    pb_pa(t_stack **src, t_stack **dest, int mod)
{
    t_stack *tmp;
    
    if(src)
    {
        tmp = (*src)->next;
        (*src)->next = *dest;
        *dest = *src;
        *src = tmp;
        if (mod == 1)
            write(1, "pa\n", 3);
        else
            write(1, "pb\n", 3);
    }
}