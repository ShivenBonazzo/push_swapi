#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	last = stack->top;
	stack->top = stack->top->next;
	while(last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ra()
