#ifndef OPEARTIONS_H
#define OPEARTIONS_H

#include "structures.h"

void	push_a(t_sort *main);
void	push_b(t_sort *main);

void	swap_a(t_sort *main);
void	swap_b(t_sort *main);
void	swap_both(t_sort *main);

void	rotate_a(t_sort *main);
void	rotate_b(t_sort *main);
void	rotate_both(t_sort *main);

void	reverse_rotate_a(t_sort *main);
void	reverse_rotate_b(t_sort *main);
void	reverse_rotate_both(t_sort *main);


#endif