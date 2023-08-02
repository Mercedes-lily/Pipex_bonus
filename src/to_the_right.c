/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_the_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:31:54 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:23:59 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		a;
	int		b;
	t_stack	*temp;

	a = (*stack_a)->index_base_3;
	b = (*stack_b)->index_base_3;
	temp = (*stack_a);
	while (temp->next->index_base_3 != a)
	{
		printf("%lld\n", temp->next->index_base_3);
		if (temp->index_base_3 < temp->next->index_base_3)
			temp = temp->next;
		else
			return (0);
	}
	temp = (*stack_b);
	while (temp->next->index_base_3 != b)
	{
		if (temp->index_base_3 > temp->next->index_base_3)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	to_the_right_p1(t_stack **stack_a, t_stack **stack_b, long long r)
{
	long long	i;
	long long	total;
	long long	index_base_3;

	total = (*stack_a)->total;
	i = 1;
	while (i <= total)
	{
		if ((*stack_a)->index_base_3 % 10 == r)
		{
			index_base_3 = (*stack_a)->index_base_3;
			push_b(stack_a, stack_b);
			(*stack_b)->index_base_3 = index_base_3;
		}
		else
			rotate_a(stack_a);
		i++;
	}
}

void	to_the_right_p2(t_stack **stack_a, t_stack **stack_b)
{
	long long	i;
	long long	total;
	long long	index_base_3;

	total = (*stack_a)->total;
	i = 1;
	while (i <= total)
	{
		index_base_3 = (*stack_a)->index_base_3;
		push_b(stack_a, stack_b);
		(*stack_b)->index_base_3 = index_base_3;
		i++;
	}
}

int	to_the_right(t_stack **stack_a, t_stack **stack_b, long long r)
{
	if (r != 4)
		to_the_right_p1(stack_a, stack_b, r);
	else
		to_the_right_p2(stack_a, stack_b);
	return (1);
}
