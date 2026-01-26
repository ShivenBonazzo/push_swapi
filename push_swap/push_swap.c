/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:29:55 by rarriola          #+#    #+#             */
/*   Updated: 2026/01/26 10:55:06 by rarriola         ###   ########.fr       */
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

static void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			sa(stack_a);
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (0);
	parse_stack(stack_a, argc, argv);
	normalize(stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	if (stack_a->size <= 5)
		sort_small(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
