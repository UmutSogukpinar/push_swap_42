#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include "structures.h"

#define MAX_INT 2147483647
#define MIN_INT -2147483648

#define SPACE_S " "
#define SPACE_C ' '

t_sort *init_sort_struct(char **args);

void    shut_program_error(t_sort *sort, char *message);
int    shut_program_success(t_sort *sort);

void 	free_2d_char_array(char **array);
t_bool	are_strs_equal(char *s1, char *s2);

char	**modify_args(int argc, char **args);
t_bool	are_args_proper(char **args);
t_bool	are_args_nul(int argc, char **args);

void	stack_a_update(t_sort *main, char **args, char *value);
void	stack_add_front(t_stack **stack, t_stack *new_stack);
int		stack_size(t_stack *stack);

#endif