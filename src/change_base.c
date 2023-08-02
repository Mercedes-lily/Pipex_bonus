/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:46:44 by vst-pier          #+#    #+#             */
/*   Updated: 2023/05/05 11:11:51 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long	change_base(long long nbr, int base)
{
	long long	digit;
	long long	new;

	digit = nbr % base;
	new = 0;
	if (nbr > 0)
		new = change_base(nbr / base, base);
	new *= 10;
	new += digit;
	return (new);
}

void	change_base_list(t_stack **stack_a, int base)
{
	int	i;
	int	total;

	i = 0;
	total = (*stack_a)->total;
	(*stack_a)->total_base_3 = change_base((*stack_a)->total, base);
	while (i < total)
	{
		(*stack_a)->index_base_3 = change_base((*stack_a)->index, base);
		(*stack_a) = (*stack_a)->next;
		i++;
	}
}
