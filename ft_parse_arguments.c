/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisney <jlaisney@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:31:22 by jlaisney          #+#    #+#             */
/*   Updated: 2023/05/07 12:19:34 by jlaisney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack *list_args(int ac, char **av)
{
    t_stack *a;
    int     i;
    int     j;
    //char    rtn_check_nbr;                //for printf

    i = 1;
    a = NULL;
    if (ac < 2)
        ft_error_print();
    if (ac == 2 && av[1][0] != '"')
        write(1, "to few arguments\n", 17);
    if (argv[1][0] == '"')
    {
        dbl_array = ft_split(av[1]);
    }
    if (ac > 2)
    {
        while (i < ac)
        {
            //printf("list args : check if is nbr\n");
            //rtn_check_nbr = not_nbr(av[1]);
            //printf("RETURN FROM --not_nbr--  : %i\n", rtn_check_nbr);
            if (not_nbr(av[i]))                                          //maybe cover check in a custom atoi here , bcuz it uses 3 funcs not readable and bad to debug
                exit(write(1, "invalid input\n", 14));
            j = ft_atoi(av[i]);
            ll_add_node(&a, ll_new_node(j));
            i++;
        }
    }

    if(ac > 2 && check_args(a, i - 1))            //had to add ac condition cuz it was always entering check args ----wtf it fixed malloc error
        exit(write(1, "Error\n", 6));
    return (a);
}