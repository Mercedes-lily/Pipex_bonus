/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:18:16 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:22:37 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	(*stack_a)->next->total = (*stack_a)->total;
	(*stack_a) = (*stack_a)->next;
	printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	(*stack_b)->next->total = (*stack_b)->total;
	(*stack_b) = (*stack_b)->next;
	printf("rb\n");
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
