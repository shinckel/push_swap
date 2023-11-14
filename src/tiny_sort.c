/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:02:44 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/14 23:19:02 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// these chuncks of code needs to be optimized!
void	sort_three(t_stack **a)
{
	if (((*a)->value > (*a)->next->value)
		&& ((*a)->next->value < (*a)->next->next->value)
		&& (*a)->next->next->value > (*a)->value)
		swap(a, 0, "sa");
	else if (((*a)->value > (*a)->next->value)
		&& ((*a)->next->value < (*a)->next->next->value)
		&& (*a)->next->next->value < (*a)->value)
		rotate(a, NULL, "ra");
	else if ((((*a)->value < (*a)->next->value)
			&& ((*a)->next->value > (*a)->next->next->value)
			&& (*a)->next->next->value > (*a)->value))
	{
		swap(a, 0, "sa");
		rotate(a, NULL, "ra");
	}
	else if ((((*a)->value < (*a)->next->value)
			&& ((*a)->next->value > (*a)->next->next->value)
			&& (*a)->next->next->value < (*a)->value))
		reverse_rotate(a, NULL, "rra");
	else
	{
		swap(a, 0, "sa");
		reverse_rotate(a, NULL, "rra");
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 4)
		push(b, a, "pb");
	else
	{
		push(b, a, "pb");
		push(b, a, "pb");
	}
	sort_three(a);
	if (stack_len(*b) == 2 && (*b)->value < (*b)->next->value)
		swap(b, 0, "sb");
	push(a, b, "pa");
	if ((*a)->value > find_last_node(*a)->value)
		rotate(a, NULL, "ra");
	if ((*a)->value > (*a)->next->value)
		swap(a, 0, "sa");
	while (stack_sorted(*a) && stack_len(*b))
		push(a, b, "pa");
	if ((*a)->value > (*a)->next->value)
		swap(a, 0, "sa");
	if (!stack_sorted(*a))
		sort_five(a, b);
}
