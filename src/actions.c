/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:57:18 by shinckel          #+#    #+#             */
/*   Updated: 2023/09/04 07:30:26 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Top node to bottom position
 * Linked list using local references - always points to the last pointer in
the list instead of to the last node. Therefore, all adittions are made by following the reference
 * t_stack_node** lastPtrRef= &head; // Start out pointing to the head pointer
 */

static void user_message(char *str)
{
	if (!ft_strncmp(str, "pa", 2))
		write(1, PA, ft_strlen(PA));
	else if (!ft_strncmp(str, "pb", 2))
		write(1, PB, ft_strlen(PB));
	else if (!ft_strncmp(str, "ra", 2))
		write(1, RA, ft_strlen(RA));
	else if (!ft_strncmp(str, "rb", 2))
		write(1, RB, ft_strlen(RB));
	else if (!ft_strncmp(str, "rr", 2))
		write(1, RR, ft_strlen(RR));
	else if (!ft_strncmp(str, "rra", 3))
		write(1, RRA, ft_strlen(RRA));
	else if (!ft_strncmp(str, "rrb", 3))
		write(1, RRB, ft_strlen(RRB));
	else if (!ft_strncmp(str, "rrr", 3))
		write(1, RRR, ft_strlen(RRR));
}

// Push a node to the top from src to dest
void	push(t_stack_node **destRef, t_stack_node **sourceRef, char *str)
{
	t_stack_node *newNode = *sourceRef;
	if (newNode == NULL) // check if protection is sufficient
		return ;
	*sourceRef = newNode->next; // Advance the source pointer
	newNode->next = *destRef; // Link the old dest off the new node
	*destRef = newNode; // Move dest to point to the new node
	user_message(str);
}

// Top node to the bottom position
void	rotate(t_stack_node **headRef, t_stack_node **tmpRef, char *str)
{
	t_stack_node	*last_node;
	int				len;

	(void)tmpRef;
	len = stack_len(*headRef);
	if (headRef == NULL || len == 1)
		return ;
	last_node = find_last_node(*headRef, false);
	*headRef = (*headRef)->next;
	last_node->next = *headRef;
	(*headRef)->next = NULL;
	if (!ft_strncmp(str, "rr", 2))
		rotate(tmpRef, 0, str);
	user_message(str);
	// last_node->next->next = NULL;
}

// Bottom to top
void	reverse_rotate(t_stack_node **headRef, t_stack_node **tmpRef, char *str)
{
	t_stack_node	*last_node;
	t_stack_node	*new_last_node;
	int				len;

	(void)tmpRef;
	(void)str;
	len = stack_len(*headRef);
	if (headRef == NULL || len == 1)
		return ;
	last_node = find_last_node(*headRef, false);
	new_last_node = find_last_node(*headRef, true);
	last_node->next = *headRef;
	new_last_node->next = NULL;
	*headRef = last_node;
	// error - I cant point the new last node to NULL. How to solve
	// ...without using prev? need to search
}


// adapt and then delete
void	rra(t_stack_node **a, bool checker)
{
	reverse_rotate(a, 0, "rra");
	if (!checker)
		write(1, RRA, ft_strlen(RRA));
}

void	rrb(t_stack_node **b, bool checker)
{
	reverse_rotate(b, 0, "rrb");
	if (!checker)
		write(1, RRB, ft_strlen(RRB));
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	reverse_rotate(a, 0, "rrr");
	reverse_rotate(b, 0, "rrr");
	if (!checker)
		write(1, RRR, ft_strlen(RRR));
}
