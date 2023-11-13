/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:02:16 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/13 22:22:20 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
// malloc, free, exit
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# include "../libft/header/libft.h"

// "e" stands for special ANSI codes
// for using the tester, make sure to comment it and use the macros defibed below
# define SUCCESS "\n\e[1;42m SUCCESS you got a sorted list! \e[0m\n"
# define REPEAT "\e[1;41m ERROR repeated numbers in stack \e[0m\n"
# define OVERFLOW "\e[1;41m ERROR number overflow \e[0m\n"
# define SYNTAX "\e[1;41m ERROR syntax error \e[0m\n"

# define PA "\e[1;48;5;027m [pa] push to stack a \e[0m\n"
# define PB "\e[1;48;5;027m [pb] push to stack b \e[0m\n"

# define RA "\e[1;48;5;129m [ra] rotate stack a \e[0m\n"
# define RB "\e[1;48;5;129m [rb] rotate stack b \e[0m\n"
# define RR "\e[1;48;5;129m [rr] rotate both stacks \e[0m\n"

# define RRA "\e[1;48;5;018m [rra] reverse rotate stack a \e[0m\n"
# define RRB "\e[1;48;5;018m [rrb] reverse rotate stack b \e[0m\n"
# define RRR "\e[1;48;5;018m [rrr] reverse rotate both stacks \e[0m\n"

# define SA "\e[1;48;5;226m [sa] swap two top numbers stack a \e[0m\n"
# define SB "\e[1;48;5;226m [sb] swap two top numbers stack b \e[0m\n"
# define SS "\e[1;48;5;226m [ss] swap two top numbers both stacks \e[0m\n"

/* ************************************************************************** */
// # define REPEAT "\e[1;41mError\e[0m\n"
// # define OVERFLOW "\e[1;41mError\e[0m\n"
// # define SYNTAX "\e[1;41mError\e[0m\n"

// # define PA "\e[1;48;5;027mpa\e[0m\n"
// # define PB "\e[1;48;5;027mpb\e[0m\n"

// # define RA "\e[1;48;5;129mra\e[0m\n"
// # define RB "\e[1;48;5;129mrb\e[0m\n"
// # define RR "\e[1;48;5;129mrr\e[0m\n"

// # define RRA "\e[1;48;5;018mrra\e[0m\n"
// # define RRB "\e[1;48;5;018mrrb\e[0m\n"
// # define RRR "\e[1;48;5;018mrrr\e[0m\n"

// # define SA "\e[1;48;5;226msa\e[0m\n"
// # define SB "\e[1;48;5;226msb\e[0m\n"
// # define SS "\e[1;48;5;226mss\e[0m\n"
/* ************************************************************************** */

// this is the blueprint of my struct
// I have to declare it "struct s_stack" because when running the block of code
// it still didn't get to the part saying: "hey, rename me as t_stack"
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// help and check list, user messages
void		print_list(t_stack *list);
void		user_message(char *str);

// handle errors & free
void		free_matrix(char **argv);
void		error_free(t_stack **a, char **argv, bool flag_argc_2);
void		free_stack(t_stack **stack);
int			error_repetition(t_stack *a, int nbr);
int			error_syntax(char *str_nbr);

// actions
void		push(t_stack **destRef, t_stack **sourceRef, char *str);
void		rotate(t_stack **headRef, t_stack **tmpRef, char *str);
void		reverse_rotate(t_stack **headRef, t_stack **tmpRef, char *str);
void		swap(t_stack **headRef, char *str);

// linked list
void		append_node(t_stack **stack, int nbr);
t_stack		*find_last_node(t_stack *head);
bool		stack_sorted(t_stack *stack);
int			stack_len(t_stack *stack);

// create stack
void		stack_init(t_stack **a, char **argv, int argc, bool flag_argc_2);
long long	*normalize(long long *numbers, int len);

// algorithms
void		radix_sort(t_stack **stack_a, t_stack **stack_b, int len);
// 3 nodes
// 5 nodes

#endif