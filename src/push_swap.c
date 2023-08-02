/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:18:09 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/19 10:32:01 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	linked_list(t_stack **stack_a)
{
	t_stack	*copy;

	copy = last(*stack_a);
	copy->next = *stack_a;
	(*stack_a)->previous = copy;
}

void	free_p(t_stack **stack_a)
{
	int		i;
	int		total;
	t_stack	*to_free;

	i = 1;
	total = (*stack_a)->total;
	if (total != 0)
	{	
		while (i++ <= total)
		{
			to_free = (*stack_a)->next;
			free((*stack_a));
			(*stack_a) = to_free;
		}
	}
	else
	{
		while ((*stack_a) != NULL)
		{
			to_free = (*stack_a)->next;
			free((*stack_a));
			(*stack_a) = to_free;
		}
	}
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->total == 2)
		swap_a(stack_a);
	else if ((*stack_a)->total == 3)
		three_algorithm(stack_a);
	else if ((*stack_a)->total <= 5)
		five_algorithm(stack_a, stack_b);
	else if ((*stack_a)->total > 5)
		big_algorithm(stack_a, stack_b);
}

void	if_argv(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**tab;

	i = 0;
	if (argc == 2)
	{	
		tab = ft_split(argv[1], ' ');
		is_number(tab);
		(*stack_a)->total = create_stack(stack_a, tab, 0);
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	else
	{	
		is_number(argv);
		(*stack_a)->total = create_stack(stack_a, argv, 1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	else
		if_argv(argc, argv, &stack_a);
	verif_min_max(stack_a);
	if (verif_doub(stack_a) == 1)
	{
		free_p(&stack_a);
		exit_with_failure();
	}
	if (is_sorted(stack_a) == 0)
		return (free_p(&stack_a), 0);
	linked_list(&stack_a);
	stack_b = initialize(0);
	algorithm(&stack_a, &stack_b);
	free_p(&stack_a);
	free(stack_b);
}
