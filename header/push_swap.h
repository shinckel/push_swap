/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:02:16 by shinckel          #+#    #+#             */
/*   Updated: 2023/09/26 23:27:34 by shinckel         ###   ########.fr       */
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

// this is the blueprint of my struct
// I have to declare it "struct s_stack" because when running the block of code
// it still didn't get to the part saying: "hey, rename me as t_stack"
typedef struct	s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}				t_stack_node;

// help and check list, user messages
void			print_list(t_stack_node **list);
void			user_message(char *str);

// handle errors & free
void			free_matrix(char **argv);
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);
void			free_stack(t_stack_node **stack);
int				error_repetition(t_stack_node *a, int nbr);
int				error_syntax(char *str_nbr);

// create stack
void			stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);

// linked list
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
void			finish_rotation(t_stack_node **s, t_stack_node *n, char c);

// algorithms
void			tiny_sort(t_stack_node **a);
void			handle_five(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);

// actions
void			push(t_stack_node **destRef, t_stack_node **sourceRef, char *str);
void			rotate(t_stack_node **headRef, t_stack_node **tmpRef, char *str);
void			reverse_rotate(t_stack_node **headRef, t_stack_node **tmpRef, char *str);
void			swap(t_stack_node **headRef, char *str);

#endif