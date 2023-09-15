/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:35:19 by shinckel          #+#    #+#             */
/*   Updated: 2023/09/01 17:25:13 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	int	len;

	len = stack_len(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
}

void	sa(t_stack_node	**a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, SA, ft_strlen(SA));
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, SB, ft_strlen(SB));
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, SS, ft_strlen(SS));
}
