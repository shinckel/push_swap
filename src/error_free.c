/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:56:17 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/13 21:56:10 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ad hoc function (deal with problems on an ad hoc basis = as they happen)
// free the 2D array created with the ft_split function
// free each row that has been created, and then the array pointer itself
// you have to start from -1... why? because -1 is the name of the program...
// ...and then you can reach the elements
void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	// why -1 here???
	free(argv - 1);
}

// ad hoc function free stack
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

// exit could return '1' instead of macro 'EXIT_FAILURE'
// free everything and finish the program
void	error_free(t_stack **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_matrix(argv);
	exit(EXIT_FAILURE);
}

// Check if there are some syntactical mistakes
// remember: your program should accept both positive and negative numbers
// *++str_nbr if the element has more than one char, check if it is a number
int	error_syntax(char *str_nbr)
{
	if (!(str_nbr[0] == '+'
			|| str_nbr[0] == '-'
			|| (str_nbr[0] >= '0' && str_nbr[0] <= '9')))
		return (1);
	if ((str_nbr[0] == '+'
			|| str_nbr[0] == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

// Loop into the stack for some repetition
int	error_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
