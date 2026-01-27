/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:33:38 by rarriola          #+#    #+#             */
/*   Updated: 2026/01/20 17:19:01 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_b == NULL || stack_b->top == NULL)
		return ;
	tmp = stack_b->top;
	stack_b->top = stack_b->top->next;
	tmp->next = stack_a->top;
	stack_a->top = tmp;
	stack_b->size -= 1;
	stack_a->size += 1;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b == NULL || stack_b->top == NULL)
		return ;
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_a == NULL || stack_a->top == NULL)
		return ;
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
