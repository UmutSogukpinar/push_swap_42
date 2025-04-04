#include "libft.h"
#include "structures.h"

t_bool are_strs_equal(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (FALSE);
	if (ft_strncmp(s1, s2, ft_strlen(s1)) == 0)
		return (TRUE);
	return (FALSE);
}

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
