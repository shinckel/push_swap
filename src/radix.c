/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:54:51 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/14 23:17:04 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int bit_index, int n)
{
	return (n >> bit_index & 1);
}

void	operations(t_stack **a, t_stack **b, int bit_index)
{
	int	size;
	int	i;

	while (*b)
		push(a, b, "pa");
	size = stack_len(*a);
	i = 0;
	while (i < size)
	{
		if ((stack_sorted(*a) && *b == NULL))
			break ;
		if (get_bit(bit_index, (*a)->value))
			rotate(a, NULL, "ra");
		else
			push(b, a, "pb");
		i++;
	}
}

void	radix_sort(t_stack **a, t_stack **b, int len)
{
	int	i;

	i = -1;
	if (len == 2)
		swap(a, 0, "sa");
	else if (len == 3)
		sort_three(a);
	else if (len == 4 || len == 5)
		sort_five(a, b);
	else
	{
		while (++i < 25)
		{
			operations(a, b, i);
			if ((stack_sorted(*a) && *b == NULL))
				break ;
		}
	}
}
