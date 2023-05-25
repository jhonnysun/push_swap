#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "../libftps/libftps.h"
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
//# include "libft/libft.h"

//maybe add unsigned int : chunk
typedef struct s_stack
{
    int             content;
    size_t          index;
    struct s_stack  *next;
} t_stack;

typedef struct s_positions
{
    int pos_first;
    int pos_last;
    int elem_top;
    int elem_bot;
    int n_rot_top;
    int n_rot_bot;
} t_positions;

//main.c
static int	check_edge(char **av, int len);
int main(int ac, char **av);

//ops_rot.c
//t_stack *find_forelast(t_stack **stack);
t_stack	*ft_lstlast(t_stack *stack);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void    ft_ra(t_stack **a, int print);
void    ft_rb(t_stack **b, int print);
void    rotate_rr(t_stack **a, t_stack **b);
void    reverse_rra(t_stack **a, int print);
void    reverse_rrb(t_stack **b, int print);
void    reverse_rrr(t_stack **a, t_stack **b);

//ops
void    ft_sa(t_stack **a, int print);
void    ft_sb(t_stack **b, int print);
void    ft_ss(t_stack **a, t_stack **b, int print);
void    pb_pa(t_stack **src, t_stack **dest, int mod);



//list_init.c
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
int	ft_lstsize(t_stack *lst);
void	ft_lstadd_back(t_stack **list, t_stack *new);
t_stack *fill_a(int *array, int len);

//create_array.c
int *create(int ac, char **av);
int *to_sort(int *sorted, int ac);
int is_sorted(int *array, int size);
int return_index(int *array, int content, int len);
void    set_index(t_stack **list, int *array, int len);

//itoa_atoi.c
int	ft_atoi(const char *str);
int	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
static int	ft_digit_len(int n);
static char	*ft_positiv_letters(int n, int count);
static char	*ft_negativ_letters(int n, int count);
static char	*ft_check_int(int n);
char	*ft_itoa(int n);

//checkargs.c
int not_sorted(char **av, int size);
int has_dup_or_char(char **av, int size);

//utils.c
int	ft_strlen(const char *s);
int	ft_isdigit(int c);
int not_nbr(char *str);
void	push_min(t_stack **a, t_stack **b);
void	push_min_sub(t_stack **a, t_stack **b, int pos);



//debugprints
//void    ll_print_list(t_stack *a);
void    print_list(t_stack *list);
void	print_array(int *array, int ac);

//chunks.c
int set_chuncksize(int elements);
/*int chunck_next(int chunksize, int max_elements);
t_positions top_bot(t_stack **a, int chunckindex, int max_elements);
t_positions n_rot(t_stack **a, int chunkckindex, int max_elements);*/

//sort_x.c
void    sort_five(t_stack **a, t_stack **b);
void    sort_four(t_stack **a, t_stack **b);
void    sort_three(t_stack **stack);
void    sub_three(t_stack **stack, int *n);





#endif


























