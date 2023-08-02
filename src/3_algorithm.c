/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:02:24 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:32:22 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	compare_nb(int nb1, int nb2)
{
	if (nb1 < nb2)
		return (-1);
	return (1);
}

void	three_algorithm_p1(t_stack **sk)
{
	if (compare_nb((*sk)->number, (*sk)->next->next->number) == -1)
	{
		if (compare_nb((*sk)->next->number, (*sk)->next->next->number) == 1)
		{
			reverse_rotate_a(sk);
			swap_a(sk);
		}
	}
	else
		reverse_rotate_a(sk);
}

void	three_algorithm_p2(t_stack **sk)
{
	if (compare_nb((*sk)->number, (*sk)->next->next->number) == -1)
		swap_a(sk);
	else
	{
		if (compare_nb((*sk)->next->number, (*sk)->next->next->number) == -1)
			rotate_a(sk);
		else
		{
			rotate_a(sk);
			swap_a(sk);
		}
	}
}

void	three_algorithm(t_stack **stack)
{
	if (compare_nb((*stack)->number, (*stack)->next->number) == -1)
		three_algorithm_p1(stack);
	else
		three_algorithm_p2(stack);
}
