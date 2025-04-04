#include "libft.h"
#include "push_swap.h"

static char *concat_all_args(int argc, char **args);
static char *append_arg(char *head, char *added);

/*
 * Joins all arguments into a single string, splits them by space,
 * and returns a modified argument array.
 * Handles both standard and quoted argument formats.
 */
char **modify_args(int argc, char **args)
{
    char	**modified_args;
    char    *head;

    head = concat_all_args(argc, args);
    modified_args = ft_split(head, SPACE_C);
    free(head);
    if (!modified_args)
        shut_program_error(NULL, "Alloc error on modify_args");
    return (modified_args);
}

/*
 * Concatenates all arguments from argv[1] to argv[argc - 1] into a single string.
 * Adds a space between each argument to prepare for later splitting.
 */
static char *concat_all_args(int argc, char **args)
{
    char    *head;
    int		i;

    i = 2;
    head = ft_strdup(args[1]);
    if (!head)
        shut_program_error(NULL, "Alloc error on concat_all_args");
    while (i < argc)
    {
        head = append_arg(head, args[i]);
        i++;
    }
    return (head);
}

/*
 * Appends a space and the given argument to the existing string.
 * Handles memory allocation and cleanup.
 */
static char *append_arg(char *head, char *added)
{
    char    *temp;

    temp = ft_strjoin(head, SPACE_S);
    free(head);
    if (!temp)
        shut_program_error(NULL, "Alloc error on append_arg");
    head = temp;
    temp = ft_strjoin(head, added);
    free(head);
    if (!temp)
        shut_program_error(NULL, "Alloc error on append_arg");
    head = temp;
    return (head);
}
