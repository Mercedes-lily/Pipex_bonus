/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:18:14 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:22:48 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	(*stack_a)->previous->total = (*stack_a)->total;
	(*stack_a) = (*stack_a)->previous;
	printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b)
{
	(*stack_b)->previous->total = (*stack_b)->total;
	(*stack_b) = (*stack_b)->previous;
	printf("rrb\n");
}

void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
