#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	s_node
{
	int		value;
	struct	s_node	*next;
}				t_node;

typedef	struct	s_stack
{
	t_node	*top;
	int		size;
}				t_stack;

t_node	*new_node(int value);
t_node *add_node(t_node *head, int value);
t_node *remove_node(t_node *head);
#endif
