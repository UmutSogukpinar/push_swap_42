#include "libft.h"
#include "structures.h"

/*
 * Returns TRUE if two strings are exactly equal in length and content.
 */
t_bool are_strs_equal(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (FALSE);
	if (ft_strncmp(s1, s2, ft_strlen(s1)) == 0)
		return (TRUE);
	return (FALSE);
}

/*
 * Frees a dynamically allocated 2D char array (null-terminated).
 */
void free_2d_char_array(char **array) 
{
	int i;

	if (!array) 
		return;
	i = 0;
	while (array[i]) 
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*
 * Checks if a stack is fully sorted in ascending order.
 */
t_bool is_sorted(t_stack *stack)
{
	if (!stack)
		return (FALSE);
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

/*
 * Checks if the stack is sorted with at most one rotation point.
 */
t_bool is_partly_sorted(t_stack *stack)
{
	t_stack *head;
	int breaks;

	if (!stack || !stack->next)
		return (FALSE);
	breaks = 0;
	head = stack;
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			breaks++;
		stack = stack->next;
	}
	if (stack->value > head->value)
		breaks++;
	return (breaks <= 1);
}
