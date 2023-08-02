/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:13:09 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 12:00:21 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

typedef struct stack
{
	long long			number;
	struct stack		*next;
	struct stack		*previous;
	long long			total;
	long long			total_base_3;
	long long			index;
	long long			index_base_3;
}	t_stack;

// 3_algorithm.c
int			compare_nb(int nb1, int nb2);
void		three_algorithm_p1(t_stack **stack);
void		three_algorithm_p2(t_stack **stack);
void		three_algorithm(t_stack **stack);

// 5_algorithm.c
int			find_minus(t_stack **stack_a);
void		swap_minus(t_stack **stack_a, t_stack **stack_b, int position);
void		find_and_swap(t_stack **stack_a, t_stack **stack_b);
void		five_algorithm(t_stack **stack_a, t_stack **stack_b);

// big_algorithm.c
void		give_index(t_stack **stack_a);
long long	give_index_p1(t_stack **s_a, long long t, long long m, long long l);
void		give_index_p2(t_stack **s_a, long long t, long long m, long long i);
void		big_algorithm(t_stack **stack_a, t_stack **stack_b);

// big_sort.c

void		big_sort_p1(int total, t_stack **p);
int			big_sort_p2(t_stack **stack_a, t_stack **stack_b);
void		big_sort_p4(t_stack **stack_a, t_stack **stack_b, int right);
int			big_sort_p3(t_stack **stack_a, t_stack **stack_b);
void		big_sort(t_stack **stack_a, t_stack **stack_b);

// change_base.c
long long	change_base(long long nbr, int base);
void		change_base_list(t_stack **stack_a, int base);

// list.c
t_stack		*last(t_stack *lst);
void		add_back(t_stack **lst, t_stack *new);
t_stack		*initialize(long long number);
int			create_stack(t_stack **stack_a, char **argv, int i);

// long_atoi.c
long long	long_atoi(char *str);

// push_swap.c

void		linked_list(t_stack **stack_a);
void		free_p(t_stack **stack_a);
void		algorithm(t_stack **stack_a, t_stack **stack_b);
void		if_argv(int argc, char **argv, t_stack **stack_a);

// push.c
void		empty_list(t_stack	**stack, t_stack **temp);
void		not_empty_list(t_stack	**stack, t_stack **temp);
void		push_start(t_stack **stack, t_stack *temp);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);

// reverse_rotate.c
void		reverse_rotate_a(t_stack **stack_a);
void		reverse_rotate_b(t_stack **stack_b);
void		reverse_rotate_r(t_stack **stack_a, t_stack **stack_b);

// rotate.c
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_r(t_stack **stack_a, t_stack **stack_b);

// swap.c
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_s(t_stack **stack_a, t_stack **stack_b);

// to_the_left.c
void		to_the_left_p1(t_stack **stack_a, t_stack **stack_b, long long r);
void		to_the_left_p2(t_stack **stack_a, t_stack **stack_b);
int			to_the_left(t_stack **stack_a, t_stack **stack_b, long long r);

// to_the_right.c
int			stack_sort(t_stack **stack_a, t_stack **stack_b);
void		to_the_right_p1(t_stack **stack_a, t_stack **stack_b, long long r);
void		to_the_right_p2(t_stack **stack_a, t_stack **stack_b);
int			to_the_right(t_stack **stack_a, t_stack **stack_b, long long r);

// verification.c
void		exit_with_failure(void);
int			is_number(char **tab_of_numbers);
void		verif_min_max(t_stack *stack_a);
int			is_sorted(t_stack *stack_a);
int			verif_doub(t_stack *stack_a);

#endif
