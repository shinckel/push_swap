/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:06:40 by shinckel          #+#    #+#             */
/*   Updated: 2023/08/05 12:15:32 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h";

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
		argv = ft_split(argv[1], 32);
	stack_init(&a, argv, argc == 2);
}