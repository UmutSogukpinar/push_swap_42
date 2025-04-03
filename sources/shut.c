#include "push_swap.h"

void    shut_program_error(char *message)
{
    if (message)
        ft_putendl_fd(message, 2);
    exit(EXIT_FAILURE);
}
