/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:18:25 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:19:02 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_minus(t_stack **stack_a)
{
	int		number;
	t_stack	*test;
	int		i;

	i = 2;
	test = (*stack_a)->next;
	number = (*stack_a)->number;
	while (i <= (*stack_a)->total)
	{
		i++;
		if (test->number < number)
			number = test->number;
		test = test->next;
	}
	return (number);
}

void	swap_minus(t_stack **stack_a, t_stack **stack_b, int position)
{
	int	i;

	if (position == 1)
		push_b(stack_a, stack_b);
	if (position == 2 || position == 3)
	{
		i = 0;
		while (i++ < position - 1)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else if (position == 4 && (*stack_a)->total == 4)
	{
		reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
	else if (position == 4 || position == 5)
	{
		i = position;
		while (i++ < 6)
			reverse_rotate_a(stack_a);
		push_b(stack_a, stack_b);
	}
}

void	find_and_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		position;
	int		number;
	t_stack	*test;

	position = 1;
	test = (*stack_a);
	number = find_minus(stack_a);
	while (number != test->number)
	{
		test = test->next;
		position += 1;
	}
	swap_minus(stack_a, stack_b, position);
}

void	five_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	find_and_swap(stack_a, stack_b);
	find_and_swap(stack_a, stack_b);
	three_algorithm(stack_a);
	if (compare_nb((*stack_b)->number, (*stack_b)->next->number) == -1)
		swap_b(stack_b);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
