/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:57:18 by shinckel          #+#    #+#             */
/*   Updated: 2023/09/26 17:35:57 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push a node to the top from sourceRef to destRef
// **destRef and sourceRef are pointers to a pointer...
// ...so you can change the real value without making a local copy of it
// doubly-linked lists
void	push(t_stack_node **destRef, t_stack_node **sourceRef, char *str)
{
	t_stack_node *newNode;

	if (*sourceRef == NULL)
		return ;
	newNode = *sourceRef;
	*sourceRef = (*sourceRef)->next;
	if (*sourceRef)
		(*sourceRef)->prev = NULL;
	newNode->prev = NULL;
	if (*destRef == NULL)
	{
		*destRef = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *destRef;
		newNode->next->prev = newNode;
		*destRef = newNode;
	}
	user_message(str);
}

// Top node to the bottom position
void	rotate(t_stack_node **headRef, t_stack_node **tmpRef, char *str)
{
	t_stack_node	*last_node;
	int				len;

	len = stack_len(*headRef);
	if (headRef == NULL || *headRef == NULL || len == 1)
		return ;
	last_node = find_last_node(*headRef);
	last_node->next = *headRef;
	*headRef = (*headRef)->next;
	(*headRef)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	if (!ft_strncmp(str, "rr", 2))
		rotate(tmpRef, NULL, "false");
	user_message(str);
}

// Bottom node to the top position
void	reverse_rotate(t_stack_node **headRef, t_stack_node **tmpRef, char *str)
{
	t_stack_node	*last;
	int				len;

	len = stack_len(*headRef);
	if (headRef == NULL || *headRef == NULL || len == 1)
		return ;
	last = find_last_node(*headRef);
	last->prev->next = NULL;
	last->next = *headRef;
	last->prev = NULL;
	*headRef = last;
	last->next->prev = last;
	if (!ft_strncmp(str, "rrr", 3))
		reverse_rotate(tmpRef, NULL, "false");
	user_message(str);
}

// Top node to the second position
void	swap(t_stack_node **headRef, char *str)
{
	int	len;

	len = stack_len(*headRef);
	if (headRef == NULL || *headRef == NULL || len == 1)
		return ;
	*headRef = (*headRef)->next;
	user_message(str);
}
