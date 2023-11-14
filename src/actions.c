/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:57:18 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/14 20:03:02 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push a node to the top from sourceRef to destRef
// **destRef and sourceRef are pointers to a pointer...
// ...so you can change the real value without making a local copy of it
// doubly-linked lists
void	push(t_stack **destRef, t_stack **sourceRef, char *str)
{
	t_stack	*new_node;

	if (*sourceRef == NULL)
		return ;
	new_node = *sourceRef;
	*sourceRef = (*sourceRef)->next;
	if (*sourceRef)
		(*sourceRef)->prev = NULL;
	new_node->prev = NULL;
	if (*destRef == NULL)
	{
		*destRef = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *destRef;
		new_node->next->prev = new_node;
		*destRef = new_node;
	}
	user_message(str);
}

// Top node to the bottom position
void	rotate(t_stack **headRef, t_stack **tmpRef, char *str)
{
	t_stack	*last_node;
	int		len;

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
void	reverse_rotate(t_stack **headRef, t_stack **tmpRef, char *str)
{
	t_stack	*last;
	int		len;

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
void	swap(t_stack **headRef, int flag, char *str)
{
	int		len;
	int		tmp;
	bool	state;

	state = true;
	len = stack_len(*headRef);
	if (headRef == NULL || *headRef == NULL || len == 1)
		return ;
	if (flag)
		state = (*headRef)->value > (*headRef)->next->value;
	if (state)
	{
		tmp = (*headRef)->value;
		(*headRef)->value = (*headRef)->next->value;
		(*headRef)->next->value = tmp;
		user_message(str);
	}
}
