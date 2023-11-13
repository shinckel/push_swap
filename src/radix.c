/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:54:51 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/13 22:02:01 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int bit_index, int n)
{
	return (n >> bit_index & 1);
}

void	operations(t_stack **stack_a, t_stack **stack_b, int bit_index)
{
	int	size;
	int	i;

	while (*stack_b)
		push(stack_a, stack_b, "pa");
	size = stack_len(*stack_a);
	i = 0;
	while (i < size)
	{
		if ((stack_sorted(*stack_a) && *stack_b == NULL))
			break ;
		if (get_bit(bit_index, (*stack_a)->value))
			rotate(stack_a, NULL, "ra");
		else
			push(stack_b, stack_a, "pb");
		i++;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	i;
	if (len == 3)
	{
		// sort 3 nodes list
		return ;
	}
	if (len == 5)
	{
		// sort 5 nodes list
		return ;
	}
	i = -1;
	while (++i < 33)
	{
		operations(stack_a, stack_b, i);
		if ((stack_sorted(*stack_a) && *stack_b == NULL))
			break ;
	}
}
