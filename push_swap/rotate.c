/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:33:48 by rarriola          #+#    #+#             */
/*   Updated: 2026/01/20 16:11:48 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*last;

	if (stack == NULL || stack->size < 2)
		return ;
	tmp = stack->top;
	last = stack->top;
	stack->top = stack->top->next;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack *stack_a)
{
	if (stack_a == NULL || stack_a->size < 2)
		return ;
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	if (stack_b == NULL || stack_b->size < 2)
		return ;
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_a->size < 2)
		return ;
	if (stack_b == NULL || stack_b->size < 2)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
