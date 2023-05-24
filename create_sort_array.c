/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sort_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:03:44 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/20 17:48:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "pushswap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				res;
	int				sign;
	int				i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = sign * (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void    print_list(t_stack *list)
{
    while(list)
    {
        printf("list_index = %li   list_Content = %i\n", list->index, list->content);
        list = list->next;
    }
}

int not_nbr(char *str)
{
	int	i;
	
	i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '+')
            return (1);
		else if (str[i] == '-' || str[i] == '+')
		{
			if (i > 0 && str[i - 1] != ' ')
				return (1);
			else if (str[i + 1] != '\0' && !ft_isdigit(str[i + 1]))
				return (1);
		}
        i++;
    }
    return (0);
}

int not_sorted(char **av, int size)
{
    int i;
    int j;

    j = size;
    i = 1;
    if (size == 1)
        return (1);
    while (i < size)
    {
        while(j > i)
        {
            if (ft_atoi(av[i]) > ft_atoi(av[j]))
            {
                //printf("array, i = %s\narray,j = %s\nj = %i\nsize = %i\n", av[i], av[j], j, size);
                return (0);
            }    
            j--;
        }
        i++;
        j = size - 1;
    }
	write(1, "is_sorted\n", 11);
    return (1);
}  

int has_dup_or_char(char **av, int size)
{
    int i;
    int j;

    i = 1;
	j = i + 1;
	if (not_nbr(av[1]))
		return (1);
    while (i < size)
    {
        while (j < size)
        {
            if (ft_atoi(av[i]) == ft_atoi(av[j]))
                return (1);
            j++;
        }
        i++;
		if (not_nbr(av[i]))
			return (1);
        j = i + 1;
    }
    return (0);
}

void	print_array(int *array, int ac)
{
	int	i;

	i = 0;
	while (i <= (ac - 2))
	{
        printf("array_index = %i   array_Content = %i\n", i, array[i]);
		i++;
	}
}

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

int return_index(int *array, int content, int len)
{
    int i;

    i = 0;
    while (i <= len)
    {
        if (content == array[i])
            return (i + 1);
        i++;
    }
    return (-1);
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

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*rtn;

	i = 0;
	rtn = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rtn)
		return (NULL);
	while (s[i] && i < (size_t)ft_strlen(s))
	{
		rtn[i] = s[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

static int	ft_digit_len(int n)
{
	int		sign;
	int		i;

	i = 0;
	sign = 0;
	if (!n)
		return (0);
	if (n < 0)
	{
		sign = 1;
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + sign);
}

static char	*ft_positiv_letters(int n, int count)
{
	char	*letters;
	int		i;

	i = 0;
	letters = (char *)malloc(sizeof(char) * (count + 1));
	if (!letters)
		return (0);
	letters[count] = '\0';
	i = count;
	while (i >= 1)
	{
		i--;
		letters[i] = n % 10 + '0';
		n = n / 10;
	}
	return (letters);
}

static char	*ft_negativ_letters(int n, int count)
{
	char	*letters;
	int		i;

	letters = NULL;
	i = 0;
	letters = (char *)malloc(sizeof(char) * (count + 1));
	if (!letters)
		return (0);
	letters[count] = '\0';
	i = count - 1;
	letters[0] = '-';
	while (i > 0)
	{
		letters[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (letters);
}

static char	*ft_check_int(int n)
{
	char	*letters;

	letters = NULL;
	if (n == 0)
	{
		letters = (char *)malloc(sizeof(char) * (2));
		letters[0] = '0';
		letters[1] = '\0';
		return (letters);
	}
	if (n >= 2147483647 || n <= -2147483648)
	{
		if (n == -2147483648)
			letters = ft_strdup("-2147483648");
		else
			letters = ft_strdup("2147483647");
		return (letters);
	}
	return ("x");
}

char	*ft_itoa(int n)
{
	int		count;
	int		sign;
	char	*letters;

	letters = NULL;
	if (n == 0 || n >= 2147483647 || n <= -2147483648)
	{
		letters = ft_check_int(n);
		return (letters);
	}
	sign = 0;
	count = ft_digit_len(n);
	if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}
	if (sign == -1)
		letters = ft_negativ_letters(n, count);
	else if (sign == 0)
		letters = ft_positiv_letters(n, count);
	if (!letters)
		return (0);
	return (letters);
}


int *create(int ac, char **av)
{
    int *filled;
    int i;
    int j;

    j = 1;
    i = 0;
    filled = malloc(sizeof(int) * ac);
    while (j <= (ac - 1))
    {
        filled[i] = atoi(av[j]);
        i++;
        j++;
    }
	return (filled);
}
//function to sort the integers in an given array and returns it with its content in ascending order
int *to_sort(int *sorted, int ac)
{
    int i;
    int j;
    int push;
    int tmp;

    i = 0;    
    j = ac - 2;
    while (i < j)
    {
        // this is for the last 2 numbers in the array
        while(j > i)
        {
            if (sorted[i] > sorted[j])
            {
                tmp = sorted[j];
				sorted[j] = sorted[i];
                sorted[i] = tmp;
            }
            j--;
        }
        //sorted[i] = tmp;
        i++;
        j = ac - 2;
    }
    return (sorted);
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

static int	check_edge(char **av, int len)
{
	 if ((len + 1) <= 2 || has_dup_or_char(av, len))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (not_sorted(av, (len)))
	{
		write(1, "1\n", 2);
		return (2);
	}
	return (0);
}
int main(int ac, char **av)
{
    int     *tosort;
    int     *sorted;
    int     len;
    t_stack *a;
	t_stack *b;
	
   // b = malloc(sizeof(t_stack));
	//b->next = NULL;
	b = NULL;
    len = (ac - 1);
	//before anything is done do the parsing here : check dup, is sorted, is not number and only 2 numbers, and max arguments allowed, quoted or not use split
	if (check_edge(av, len) == 2)
		return (0);
	else if (check_edge(av, len))
		return (1);
	tosort = create(ac, av);
    a = fill_a(tosort, len, a);    
    sorted = to_sort(tosort, ac);
    set_index(&a, sorted, len);
	//print_array(sorted, ac);
	//pa_pb(&a, &b, 2);
	//pa_pb(&a, &b, 2);
    print_list(a);
	
	write(1, "\n\n", 2);
	print_list(b);
	write(1, "\n\n", 2);
	
	//sa_sb(&a, &b, 1, 0);
    rra_rrb(&a, &b, 3, 1);	
	//ra_rb(&a, &b, 1, 0);
    print_list(a);
	write(1, "\n\n", 2);
	print_list(b);
	write(1, "\n\n", 2);
	
	
   
    return (0);
}