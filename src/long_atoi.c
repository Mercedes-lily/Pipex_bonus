/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:03:07 by vst-pier          #+#    #+#             */
/*   Updated: 2023/04/07 17:04:27 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long	long_atoi(char *str)
{
	long long	i;
	long long	nb;
	long long	multiple;

	i = 0;
	nb = 0;
	multiple = 1;
	if (!str)
		return (0);
	if (str[i] == '-')
	{	
		multiple = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i++;
	}
	return (multiple * nb);
}
