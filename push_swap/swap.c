/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:29:49 by rarriola          #+#    #+#             */
/*   Updated: 2026/01/20 15:44:16 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
}

void	sa(t_stack *stack_a)
{
	if (stack_a->size < 2)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	if (stack_b->size < 2)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
