/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:34:41 by rarriola          #+#    #+#             */
/*   Updated: 2026/01/26 10:58:51 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}				t_stack;

/* Stack Utils */
t_node	*new_node(int value);
t_node	*add_node(t_node *head, int value);
t_node	*remove_node(t_node *head);
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);
void	free_matrix(char **argv);
void	error_exit(t_stack *stack, char **args);

/* Parsing & String Utils */
char	*input(int argc, char **argv);
int		is_valid(char *str);
long	ft_atol(const char *str);
int		check_duplicate(t_stack *stack, int value);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

/* Operations */
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_b, t_stack *stack_a);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* Algorithm */
void	parse_stack(t_stack *stack_a, int argc, char **argv);
int		is_sorted(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	normalize(t_stack *stack);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
void	push_back_to_a(t_stack *stack_a, t_stack *stack_b);
int		find_max_index(t_stack *stack);
int		find_min_index(t_stack *stack);

#endif
