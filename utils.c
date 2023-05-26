/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:07:40 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/25 16:07:40 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int not_nbr(char *str)
{
    while (*str)
    {
        if (!ft_isdigit(*str) && *str != ' ' && *str != '-' && *str != '+')
            return (1);
        str++;
    }
    return (0);
}
/*
void	push_min_sub(t_stack **a, t_stack **b, int pos)
{
	int	stacksize;

	stacksize = ft_lstsize(*a);
	printf("position is = %i\n", pos);
	if (pos != 0)
	{
		if (pos > (stacksize / 2))
		{
			while (pos > 0)
			{
				reverse_rra(a, 1);

				pos--;
			}
		}
		else
		{	
			while (pos < stacksize - 1)
			{
				ft_ra(a, 1);
				pos++;
			}
		}
	}
	printf("will push : %i\n", (*a)->content);
}
*/
void push_min_sub(t_stack **a, t_stack **b, int pos)
{
    int stacksize = ft_lstsize(*a);
    int node_pos = stacksize - pos;

	//printf("pos = %i\n", pos);
	(void)node_pos;
	(void)b;
    if (pos != 0)
    {
        if (pos > (stacksize / 2))
        {
            // Rotate in the opposite direction (shortest way)
            while (pos < stacksize)
            {
                reverse_rra(a, 1);
                pos++;
            }
        }
        else
        {
            // Rotate in the normal direction (shortest way)
            while (pos > 0)
            {
                ft_ra(a, 1);
                pos--;
            }
        }
    }
	//printf("to push = %i\n", (*a)->content);
}

void push_min(t_stack **a, t_stack **b)
{
    t_stack *tmp = *a;
    int smallest = tmp->content;
    int pos = 0;
    int currentPos = 0;

    while (tmp)
    {
        if (tmp->content < smallest)
        {
            smallest = tmp->content;
            pos = currentPos; // Update the position only when a smaller element is found
        }
        tmp = tmp->next;
        currentPos++;
    }
    push_min_sub(a, b, pos);
}
/*
void    push_min(t_stack **a, t_stack **b)
{
    t_stack    *tmp;
    int        smallest;
    int    pos;

    pos = 0;
    tmp = *a;
    smallest = tmp->content; 
    while (tmp->next)
    {
        if (tmp->content < smallest)
		{
			smallest = tmp->content;
	        pos++;
		}
	    tmp = tmp->next;
    }
    push_min_sub(a, b, pos);
}
*/