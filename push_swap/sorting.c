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
	int i;
	int min;
	int min_index;

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

void	normalize(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack->top;
	while(current)
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

void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int max_index;

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
