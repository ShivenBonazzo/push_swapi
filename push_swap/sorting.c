/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:17:08 by rarriola          #+#    #+#             */
/*   Updated: 2026/01/26 10:48:22 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	t_node	*current;

	if (!stack_a || !stack_a->top)
		return (1);
	current = stack_a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_stack *stack_a)
{
	int		first;
	int		second;
	int		third;

	if (is_sorted(stack_a))
		return ;
	first = stack_a->top->value;
	second = stack_a->top->next->value;
	third = stack_a->top->next->next->value;
	if (first > second && first > third)
		ra(stack_a);
	else if (second > first && second > third)
		rra(stack_a);
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);
}

int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		i;
	int		min;
	int		min_index;

	current = stack->top;
	min = current->value;
	min_index = 0;
	i = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_index = i;
		}
		i++;
		current = current->next;
	}
	return (min_index);
}

void	push_min_to_top(t_stack *stack)
{
	int	min_index;

	min_index = find_min_index(stack);
	if (min_index <= stack->size / 2)
	{
		while (min_index-- > 0)
			ra(stack);
	}
	else
	{
		while (min_index++ < stack->size)
			rra(stack);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_min_to_top(stack_a);
	pb(stack_b, stack_a);
	push_min_to_top(stack_a);
	pb(stack_b, stack_a);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
