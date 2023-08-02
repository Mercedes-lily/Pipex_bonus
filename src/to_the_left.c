/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_the_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:31:54 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:23:20 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	to_the_left_p1(t_stack **stack_a, t_stack **stack_b, long long r)
{
	long long	i;
	long long	total;
	long long	index_base_3;

	i = 1;
	total = (*stack_b)->total;
	while (i <= total)
	{
		if ((*stack_b)->index_base_3 % 10 == r)
		{
			index_base_3 = (*stack_b)->index_base_3;
			push_a(stack_a, stack_b);
			(*stack_a)->index_base_3 = index_base_3;
		}
		else
			rotate_b(stack_b);
		i++;
	}
}

void	to_the_left_p2(t_stack **stack_a, t_stack **stack_b)
{
	long long	i;
	long long	total;
	long long	index_base_3;

	i = 1;
	total = (*stack_b)->total;
	while (i <= total)
	{
		index_base_3 = (*stack_b)->index_base_3;
		push_a(stack_a, stack_b);
		(*stack_a)->index_base_3 = index_base_3;
		i++;
	}
}

int	to_the_left(t_stack **stack_a, t_stack **stack_b, long long r)
{
	if (r != 0)
		to_the_left_p1(stack_a, stack_b, r);
	else
		to_the_left_p2(stack_a, stack_b);
	return (0);
}
