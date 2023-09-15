/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:39:52 by shinckel          #+#    #+#             */
/*   Updated: 2023/08/15 18:16:59 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack_node **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	(void)flag_argc_2;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			write(1, OVERFLOW, ft_strlen(OVERFLOW));
			error_free(a, argv, flag_argc_2);
		}
		if (error_repetition(*a, (int)nbr))
		{
			write(1, REPEAT, ft_strlen(REPEAT));
			error_free(a, argv, flag_argc_2);
		}
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		free_matrix(argv);
}
