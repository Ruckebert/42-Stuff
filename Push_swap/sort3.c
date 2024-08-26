/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:23:54 by aruckenb          #+#    #+#             */
/*   Updated: 2024/08/26 10:07:04 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_and_top(char ***number, char ***stack_b)
{
	pa_b(stack_b, number);
	write(1, "pa\n", 3);
	top_to_bottom(number, stack_b, 1);
}

void	sort_5(char ***number, char ***stack_b)
{
	int	placement;
	int	i;

	placement = 0;
	i = 0;
	if (ft_last(*number) == 5)
	{
		while (i <= 1)
		{
			placement = next_number(number, i);
			first_position(number, stack_b, placement, 1);
			pa_b(number, stack_b);
			write(1, "pb\n", 3);
			i++;
		}
		sort_3(number, stack_b);
		if (ft_atoi(*stack_b[0]) < ft_atoi(*stack_b[1]))
		{
			swap_first(*stack_b);
			write(1, "sb\n", 3);
		}
		push_and_top(number, stack_b);
		push_and_top(number, stack_b);
	}
}
