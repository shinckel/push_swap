/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:12:51 by shinckel          #+#    #+#             */
/*   Updated: 2023/09/04 08:15:17 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// give positions: last node or the previous to it (assuming last potision)
t_stack_node	*find_last_node(t_stack_node *head, bool find_previous)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
	{
		if (find_previous && head->next->next == NULL)
			return (head);
		head = head->next;
	}
	return (head);
}

// Search for the last node and append
// void	append_node(t_stack_node **stack, int nbr)
// {
// 	t_stack_node	*node;
// 	t_stack_node	*last_node;

// 	if (NULL == stack)
// 		return ;
// 	node = malloc(sizeof(t_stack_node));
// 	if (NULL == node)
// 		return ;
// 	node->next = NULL;
// 	node->value = nbr;
// 	if (NULL == *stack)
// 	{
// 		*stack = node;
// 	}
// 	else
// 	{
// 		last_node = find_last_node(*stack, 0);
// 		last_node->next = node;
// 	}
// }

void static	create_in_stack(t_stack_node **headRef, int nbr)
{
	t_stack_node *node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	node->value = nbr;
	node->next = *headRef;
	*headRef = node;
}

// adds a pointer to the last next pointer instead of last node
void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node **lastRef;

	lastRef = stack;
	create_in_stack(lastRef, nbr);
	lastRef = &((*lastRef)->next);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}