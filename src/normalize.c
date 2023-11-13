/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:27:58 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/13 22:00:55 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	find_bigger(long long *numbers, int len)
{
	int			i;
	long long	bigger;

	bigger = numbers[0];
	i = 0;
	while (i < len)
	{
		if (numbers[i] > bigger)
			bigger = numbers[i];
		i++;
	}
	return (bigger);
}

long long	*normalize(long long *numbers, int len)
{
	int			i;
	long long	*nums;
	int			j;
	int			smaller;
	long long	bigger;

	bigger = find_bigger(numbers, len);
	nums = malloc(sizeof(long long) * len);
	i = 0;
	while (i < len)
	{
		smaller = 0;
		j = 0;
		while (j < len)
		{
			if (numbers[j] < numbers[smaller])
				smaller = j;
			j++;
		}
		numbers[smaller] = bigger + 1;
		nums[smaller] = i;
		i++;
	}
	free(numbers);
	return (nums);
}
