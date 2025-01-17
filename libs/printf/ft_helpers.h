/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:15:07 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 16:15:10 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPERS_H
# define FT_HELPERS_H

# include <stdarg.h>

int		ft_put_char(char c);
int		ft_str_len(char *str);
int		ft_print_char(va_list args);
int		ft_print_str(va_list args);

int		ft_print_int(va_list args, char *base);
int		ft_print_uns(va_list args, char *base);

int		ft_print_adress(va_list args, char *base);

#endif