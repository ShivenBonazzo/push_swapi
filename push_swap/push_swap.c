/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:29:55 by rarriola          #+#    #+#             */
/*   Updated: 2026/01/20 18:40:56 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	parse_stack(t_stack *stack_a, int argc, char **argv)
{
	char	*input_str;
	char	**args;
	long	n;
	int		i;

	input_str = input(argc, argv);
	args = ft_split(input_str, ' ');
	free(input_str);
	i = 0;
	while (args[i])
		i++;
	while (--i >= 0)
	{
		if (!is_valid(args[i]))
			error_exit(stack_a, args);
		n = ft_atol(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_exit(stack_a, args);
		if (check_duplicate(stack_a, (int)n))
			error_exit(stack_a, args);
		stack_a->top = add_node(stack_a->top, (int)n);
		stack_a->size++;
	}
	free_matrix(args);
}
int	is_sorted(t_stack *stack_a)
{
	t_node *current;

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
	t_node *current;
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
	else if (second > first)
		sa(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	if (!stack_a)
		return (0);
	parse_stack(stack_a, argc, argv);
	free_stack(stack_a);
	return (0);
}
