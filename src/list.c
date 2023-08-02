/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:04:47 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:26:35 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*last(t_stack *lst)
{
	t_stack	*head;

	head = lst;
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}

void	add_back(t_stack **lst, t_stack *new)
{
	t_stack	*head;

	if (*lst)
	{
		head = last(*lst);
		head->next = new;
		new->previous = head;
	}
	else
		*lst = new;
}

t_stack	*initialize(long long number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->number = number;
	new->next = NULL;
	new->previous = NULL;
	new->total = 0;
	new->total_base_3 = 0;
	new->index = 0;
	new->index_base_3 = 0;
	return (new);
}

int	create_stack(t_stack **stack_a, char **argv, int i)
{
	t_stack	*temp;
	int		total;

	total = 0;
	while (argv[i])
	{
		add_back(stack_a, initialize(long_atoi(argv[i])));
		i++;
	}
	temp = (*stack_a);
	while (temp != NULL)
	{
		total++;
		temp = temp->next;
	}
	return (total);
}
