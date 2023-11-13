/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:06:40 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/13 22:22:43 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
- [ ]  Radix
- [ ]  A box for 1
- [ ]  B box for 0

- [ ]  Check if is digit or negative
- [ ]  Check duplicates
- [ ]  Check INT MAX and INT MIN
- [ ]  Create stack (structures)
- [ ]  Sort Numbers
    - [ ]  check order
    - [ ]  Sort_two
    - [ ]  Sort_three
    - [ ]  Sort_five
    - [ ]  search for the minimum value in the stack and allocate the index in ascending order starting from 1
    - [ ]  Sort_long
        - [ ]  find the list size
        - [ ]  check order
        - [ ]  transform number in bits (ex. ((*stack→indez >> i) % 2)
            - [ ]  if bit == 1 (rotate) if bit == 0 (push b)
            - [ ]  when in order, push a
    - [ ]  clean the stack
*/

// first, check if input is correct
// then, create the stack and sort it!

// if the user mix inputs? 1 2 3 "4 5 6" 8 9
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	(void)b;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, argc, argc == 2);
	printf("before: \n");
	print_list(a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			swap(&a, "sa");
		else if (stack_len(a) == 3)
			return (1); //implement function for 3 numbers
		else if (stack_len(a) == 5)
			return (1); //implement function for 5 numbers
		else
			radix_sort(&a, &b, stack_len(a));
	}
	printf("after: \n");
	print_list(a);
	free_stack(&a);
	write(1, SUCCESS, ft_strlen(SUCCESS)); //for testing it, comment this line
}
