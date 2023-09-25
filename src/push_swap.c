/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:33:15 by shinckel          #+#    #+#             */
/*   Updated: 2023/09/01 17:21:51 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cheapest_node tops is a, relative target_node tops in b
static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rotate(a, b, "rr");
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		reverse_rotate(a, b, "rrr");
	set_current_position(*a);
	set_current_position(*b);
}

// Conclude the rotation of the stacks 
void	finish_rotation(t_stack_node **stack,
							t_stack_node *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate(stack, NULL, "ra");
			else
				reverse_rotate(stack, NULL, "rra");
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate(stack, NULL, "rb");
			else
				reverse_rotate(stack, NULL, "rrb");
		}
	}
}

// Move the node from 'b' to 'a'
// With the metadata available in the node:
// 1 - Make the target nodes emerge 
// 2 - Push in 'a'
static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	push(a, b, "pa");
}

// Push all nodes in 'b'
// For every configuration choose the "cheapest_node"
// Push everything back in 'a' in order
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			push(b, a, "pb");
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			rotate(a, NULL, "ra");
	else
		while (*a != smallest)
			reverse_rotate(a, NULL, "rra");
}
