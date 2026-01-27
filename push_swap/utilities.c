/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarriola <rarriola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:29:36 by rarriola          #+#    #+#             */
/*   Updated: 2026/01/20 15:38:39 by rarriola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_node	*add_node(t_node *head, int value)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
		return (NULL);
	node->next = head;
	return (node);
}

t_node	*remove_node(t_node *head)
{
	t_node	*tmp;

	if (head == NULL)
		return (NULL);
	tmp = head->next;
	free(head);
	return (tmp);
}

char	*input(int argc, char **argv)
{
	char	*result;
	int		i;
	char	*tmp;

	result = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		tmp = result;
		result = ft_strjoin(result, argv[i]);
		free(tmp);
		tmp = result;
		result = ft_strjoin(result, " ");
		free(tmp);
		i++;
	}
	return (result);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
