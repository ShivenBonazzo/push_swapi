#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_node *add_node(t_node *head, int value)
{
	t_node *node;

	node = new_node(value);
	if (!node)
		return (NULL);
	node->next = head;
	return (node);
}

t_node *remove_node(t_node *head)
{
	t_node *tmp;

	if (head == NULL)
		return (NULL);
	tmp = head->next;
	free(head);
	return (tmp);
}
