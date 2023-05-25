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

void	push_min_sub(t_stack **a, t_stack **b, int pos)
{
	int	stacksize;
	int	node_pos;

	node_pos = stacksize - pos;
	stacksize = ft_lstsize(*a);
	printf("position is = %i\n", pos);
	if (pos != 0)
	{
		if (node_pos > (stacksize / 2))
		{
			while (pos > 0)
			{
				reverse_rra(a, 1);

				pos--;
			}
		}
		else
		{	
			while (pos < stacksize)
			{
				ft_ra(a, 1);
				pos++;
			}
		}
	}
	printf("content of head a = %i\n", (*a)->content);
}

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
        tmp = tmp->next;
        if (tmp && tmp->content < smallest)
            smallest = tmp->content;
        else
            break ;
        pos++;
    }
    push_min_sub(a, b, pos);
}

