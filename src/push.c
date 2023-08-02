/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:18:12 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:17:54 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	empty_list(t_stack	**stack, t_stack **temp)
{
	free_p(stack);
	(*stack) = (*temp);
	(*stack)->next = (*temp);
	(*stack)->previous = (*temp);
	(*stack)->total = 1;
}

void	not_empty_list(t_stack	**stack, t_stack **temp)
{
	(*temp)->previous = (*stack)->previous;
	(*temp)->next = (*stack);
	(*stack)->previous = (*temp);
	(*stack) = (*stack)->previous->previous;
	(*stack)->total = 1;
	(*stack)->next = (*temp);
	(*stack) = (*stack)->next;
	(*stack)->total = (*stack)->next->total + 1;
}

void	push_start(t_stack **stack, t_stack *temp)
{
	t_stack	*t;

	t = (*stack);
	if (temp->total == 2)
	{
		(*stack) = (*stack)->next;
		(*stack)->next = (*stack);
		(*stack)->previous = (*stack);
		(*stack)->total = 1;
		free(t);
	}
	else if (temp->total == 1)
	{
		(*stack)->total = 0;
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->previous = temp->previous;
		(*stack) = (*stack)->previous;
		(*stack)->next = temp->next;
		(*stack) = (*stack)->next;
		(*stack)->total = temp->total - 1;
		free(t);
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = initialize(0);
	temp->number = (*stack_b)->number;
	temp->next = (*stack_b)->next;
	temp->previous = (*stack_b)->previous;
	temp->total = (*stack_b)->total;
	if ((*stack_b)->total == 1)
	{
		free((*stack_b));
		(*stack_b) = NULL;
		(*stack_b) = initialize(0);
		(*stack_b)->total = 1;
	}
	if ((*stack_b)->total != 0)
	{
		push_start(stack_b, temp);
		if ((*stack_a)->total == 0)
			empty_list(stack_a, &temp);
		else
			not_empty_list(stack_a, &temp);
	}
	printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = initialize(0);
	temp->number = (*stack_a)->number;
	temp->next = (*stack_a)->next;
	temp->previous = (*stack_a)->previous;
	temp->total = (*stack_a)->total;
	if ((*stack_a)->total == 1)
	{
		free((*stack_a));
		(*stack_a) = initialize(0);
		(*stack_a)->total = 1;
	}
	if ((*stack_a)->total != 0)
	{
		push_start(stack_a, temp);
		if ((*stack_b)->total == 0)
			empty_list(stack_b, &temp);
		else
			not_empty_list(stack_b, &temp);
	}
	printf("pb\n");
}
