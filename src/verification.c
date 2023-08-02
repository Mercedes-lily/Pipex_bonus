/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:58:59 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/09 13:04:21 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exit_with_failure(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

int	is_number(char **tab_of_numbers)
{
	int	i;
	int	j;

	i = 1;
	j = 0 ;
	while (tab_of_numbers[i])
	{
		if ((tab_of_numbers[i][0] == '-' && tab_of_numbers[i][1] != '\0')
			|| (tab_of_numbers[i][0] >= '0' && tab_of_numbers[i][0] <= '9'))
			j++;
		else
			exit_with_failure();
		while (tab_of_numbers[i][j])
		{
			if (tab_of_numbers[i][j] >= '0' && tab_of_numbers[i][j] <= '9')
				j++;
			else
				exit_with_failure();
		}
		j = 0;
		i++;
	}
	return (0);
}

void	verif_min_max(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp)
	{
		if (temp->number >= INT_MIN && temp->number <= INT_MAX)
			temp = temp->next;
		else
		{
			free_p(&stack_a);
			exit_with_failure();
		}
	}
}

int	is_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->number > stack_a->next->number)
			return (1);
		else
			stack_a = stack_a->next;
	}
	return (0);
}

int	verif_doub(t_stack *stack_a)
{
	t_stack	*verif;

	while (stack_a)
	{
		verif = stack_a->next;
		while (verif)
		{
			if (stack_a->number != verif->number)
				verif = verif->next;
			else
				return (1);
		}
		stack_a = stack_a->next;
	}
	return (0);
}
