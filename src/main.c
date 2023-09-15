/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:06:40 by shinckel          #+#    #+#             */
/*   Updated: 2023/09/04 07:28:55 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_stack_node **list)
{
	t_stack_node *current = *list;

	while (current != NULL)
	{
		printf("%i \n", current->value);
		current = current->next;
	}
}

// first, check in input is correct
// then, create the stack and sort it!

// check again else if statement... if the user mix inputs? 1 2 3 "4 5 6" 8 9
// stack_init(&a, argv, argc == 2); - &a is a pointer to a pointer, so I can change de real value without making a local copy of it
// is is taking strings as arguments of the numbers I want to populate the stack
// it is a pointer to a pointer, that initially is NULL

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, argc == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	print_list(&a);
	free_stack(&a);
	write(1, SUCCESS, ft_strlen(SUCCESS));
}