#ifndef ACTIONS_H
#define ACTIONS_H

#include "structures.h"

void	push(t_stack **source, t_stack **target);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

#endif