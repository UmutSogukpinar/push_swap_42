/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:09:58 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 16:09:59 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				index;
	unsigned char	new_c;

	new_c = (unsigned char) c;
	index = ft_strlen(s);
	if (s[index] == new_c)
		return ((char *) &s[index]);
	while (index >= 0)
	{
		if (s[index] == new_c)
			return ((char *)(s + index));
		index--;
	}
	return (NULL);
}
