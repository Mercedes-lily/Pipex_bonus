/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:15:04 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:10:32 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	big_sort_p1(int total, t_stack **stack)
{
	int	i;

	i = 1;
	while (i <= total)
	{
		(*stack)->index_base_3 /= 10;
		(*stack) = (*stack)->next;
		i++;
	}
}

int	big_sort_p2(t_stack **stack_a, t_stack **stack_b)
{
	int	total_base_3;
	int	total;
	int	j;

	j = 4;
	total = (*stack_b)->total;
	total_base_3 = (*stack_b)->total_base_3;
	big_sort_p1(total, stack_b);
	while (j >= 0)
	{
		to_the_left(stack_a, stack_b, j);
		j--;
	}
	(*stack_a)->total = total;
	total_base_3 /= 10;
	(*stack_a)->total_base_3 = total_base_3;
	return (total_base_3);
}

void	big_sort_p4(t_stack **stack_a, t_stack **stack_b, int right)
{
	int	i;
	int	total;

	i = 1;
	total = (*stack_b)->total;
	if ((*stack_b)->total_base_3 == 0 && right == 1)
	{
		while (i <= total)
		{
			push_a(stack_a, stack_b);
			i++;
		}
	}
}

int	big_sort_p3(t_stack **stack_a, t_stack **stack_b)
{
	int	total_base_3;
	int	total;
	int	j;

	j = 0;
	total = (*stack_a)->total;
	total_base_3 = (*stack_a)->total_base_3;
	if ((*stack_a)->total_base_3 != 0)
	{
		big_sort_p1(total, stack_a);
		while (j <= 4)
		{
			to_the_right(stack_a, stack_b, j);
			j++;
		}
	}
	(*stack_b)->total = total;
	total_base_3 /= 10;
	(*stack_b)->total_base_3 = total_base_3;
	return (total_base_3);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{	
	int	total;
	int	total_base_3;
	int	right;
	int	j;

	j = -1;
	total = (*stack_a)->total;
	total_base_3 = (*stack_a)->total_base_3;
	while (j++ <= 4)
		to_the_right(stack_a, stack_b, j);
	total_base_3 /= 10;
	(*stack_b)->total = total;
	(*stack_b)->total_base_3 = total_base_3;
	while ((*stack_b)->total_base_3 != 0)
	{
		total_base_3 = big_sort_p2(stack_a, stack_b);
		right = 0;
		if ((*stack_a)->total_base_3 != 0)
			right = 1;
		big_sort_p3(stack_a, stack_b);
		big_sort_p4(stack_a, stack_b, right);
	}
}
