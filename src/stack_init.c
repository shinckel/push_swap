/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:39:52 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/14 22:35:52 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
// The functions below are helpers. You can print the list and actions!
void	user_message(char *str)
{
	if (!ft_strncmp(str, "pa", 2))
		write(1, PA, ft_strlen(PA));
	else if (!ft_strncmp(str, "pb", 2))
		write(1, PB, ft_strlen(PB));
	else if (!ft_strncmp(str, "rra", 3))
		write(1, RRA, ft_strlen(RRA));
	else if (!ft_strncmp(str, "rrb", 3))
		write(1, RRB, ft_strlen(RRB));
	else if (!ft_strncmp(str, "rrr", 3))
		write(1, RRR, ft_strlen(RRR));
	else if (!ft_strncmp(str, "ra", 2))
		write(1, RA, ft_strlen(RA));
	else if (!ft_strncmp(str, "rb", 2))
		write(1, RB, ft_strlen(RB));
	else if (!ft_strncmp(str, "rr", 2))
		write(1, RR, ft_strlen(RR));
	else if (!ft_strncmp(str, "sa", 2))
		write(1, SA, ft_strlen(SA));
	else if (!ft_strncmp(str, "sb", 2))
		write(1, SB, ft_strlen(SB));
	else if (!ft_strncmp(str, "ss", 2))
		write(1, SS, ft_strlen(SS));
}

void	print_list(t_stack *list)
{
	while (list)
	{
		printf("%i\n", list->value);
		list = list->next;
	}
}
/* ************************************************************************** */

static void	create_list(t_stack **a, long long *numbers, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		append_node(a, numbers[i]);
		i++;
	}
	free (numbers);
}

// check for errors and then create the stack!
void	stack_init(t_stack **a, char **argv, int argc, bool flag_argc_2)
{
	long		nbr;
	int			i;
	long long	*stack;

	i = 0;
	stack = malloc(sizeof(long long) * (argc - 1));
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atoll(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			write(1, OVERFLOW, ft_strlen(OVERFLOW));
			error_free(a, argv, flag_argc_2);
		}
		stack[i] = (int)nbr;
		++i;
	}
	if (error_repetition(stack, argc - 1))
		error_free(a, argv, flag_argc_2);
	stack = normalize(stack, argc - 1);
	create_list(a, stack, argc);
	if (flag_argc_2)
		free_matrix(argv);
}
