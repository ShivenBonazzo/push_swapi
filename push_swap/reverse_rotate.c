/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:33:55 by rarriola          #+#    #+#             */
/*   Updated: 2026/01/20 16:25:18 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*penultimate;
	t_node	*last;

	if (stack == NULL || stack->size < 2)
		return ;
	penultimate = stack->top;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	last = penultimate->next;
	last->next = stack->top;
	stack->top = last;
	penultimate->next = NULL;
}

void	rra(t_stack *stack_a)
{
	if (stack_a == NULL || stack_a->size < 2)
		return ;
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	if (stack_b == NULL || stack_b->size < 2)
		return ;
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_a->size < 2)
		return ;
	if (stack_b == NULL || stack_b->size < 2)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
