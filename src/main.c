/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:06:40 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/14 23:16:07 by shinckel         ###   ########.fr       */
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
    - [ ]  search for the minimum value in the stack and allocate the 
	index in ascending order starting from 1
    - [ ]  Sort_long
        - [ ]  find the list size
        - [ ]  check order
        - [ ]  transform number in bits (ex. ((*stack→indez >> i) % 2)
            - [ ]  if bit == 1 (rotate) if bit == 0 (push b)
            - [ ]  when in order, push a
    - [ ]  clean the stack
*/

int	arg_counter(char **str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i + 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = argc;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = arg_counter(argv);
	}
	else
		argv += 1;
	stack_init(&a, argv, argc, size == 2);
	if (!stack_sorted(a))
		radix_sort(&a, &b, stack_len(a));
	free_stack(&a);
}
// write(1, SUCCESS, ft_strlen(SUCCESS));