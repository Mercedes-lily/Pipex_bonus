/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:19:13 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:57:13 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long	give_index_p1(t_stack **s_a, long long t, long long m, long long l)
{
	int		i;
	t_stack	*temp;

	temp = (*s_a);
	i = 0;
	m = INT_MAX;
	while (i++ <= t)
	{
		if (temp->number < m && temp->number > l)
			m = temp->number;
		temp = temp->next;
	}
	return (m);
}

void	give_index_p2(t_stack **s_a, long long t, long long m, long long i)
{
	int		j;
	t_stack	*temp;

	temp = (*s_a);
	j = 0;
	while (j++ <= t)
	{
		if (temp->number == m)
			temp->index = i;
		temp = temp->next;
	}
}

void	give_index(t_stack **stack_a)
{
	int			minus;
	long long	limit;
	int			i;
	int			total;
	int			index;

	i = 1;
	limit = INT_MIN;
	index = 1;
	total = (*stack_a)->total;
	while ((i++ <= total))
	{
		minus = give_index_p1(stack_a, total, minus, limit);
		give_index_p2(stack_a, total, minus, index);
		index++;
		limit = minus;
	}
}

void	big_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	give_index(stack_a);
	change_base_list(stack_a, 5);
	big_sort(stack_a, stack_b);
}
