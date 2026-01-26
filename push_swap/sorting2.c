/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:00:00 by rarriola          #+#    #+#             */
/*   Updated: 2026/01/26 11:00:00 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack->top;
	while (current)
	{
		current->index = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->value < current->value)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}

int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		max_pos;
	int		i;

	current = stack->top;
	max = current->index;
	max_pos = 0;
	i = 0;
	while (current)
	{
		if (current->index > max)
		{
			max = current->index;
			max_pos = i;
		}
		i++;
		current = current->next;
	}
	return (max_pos);
}

void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max_index;

	while (stack_b->size > 0)
	{
		max_index = find_max_index(stack_b);
		if (max_index <= stack_b->size / 2)
		{
			while (max_index-- > 0)
				rb(stack_b);
		}
		else
		{
			while (max_index++ < stack_b->size)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	i;

	chunk_size = stack_a->size / 5;
	if (stack_a->size > 100)
		chunk_size = stack_a->size / 11;
	i = 0;
	while (stack_a->size > 0)
	{
		if (stack_a->top->index <= i)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			i++;
		}
		else if (stack_a->top->index <= i + chunk_size)
		{
			pb(stack_b, stack_a);
			i++;
		}
		else
			ra(stack_a);
	}
	push_back_to_a(stack_a, stack_b);
}
