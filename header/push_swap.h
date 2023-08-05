/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:02:16 by shinckel          #+#    #+#             */
/*   Updated: 2023/08/05 12:28:08 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
/* malloc, free, exit */
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# include "libft/header/libft.h"

/* "e" stands for special ANSI codes */
# define SUCCESS "\e[1;42m SUCCESS \e[0m \n"
# define REPEAT "\e[1;41m ERROR repeated numbers in stack \e[0m"

// this is the blueprint of my struct
// I have to declare it "struct s_stack" because when running the block of code
// it still didn't get to the part saying: "hey, rename me as t_stack"
typedef struct	s_stack_node
{
	int				value;
	int				current_position;
	int				final_index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack_node;

#endif