/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:06:04 by aruckenb          #+#    #+#             */
/*   Updated: 2024/06/25 10:06:06 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_and_reverse(char ***number, char ***stack_b)
{
	swap_first(*number);
	write(1, "sa\n", 3);
	rra_b(number, stack_b);
	write(1, "rra\n", 4);
}

void	swap_and_back(char ***number, char ***stack_b)
{
	swap_first(*number);
	write(1, "sa\n", 3);
	ra_b(number, stack_b);
	write(1, "ra\n", 3);
}

void	top_to_bottom(char ***number, char ***stack_b, int i)
{
	ra_b(number, stack_b);
	if (i == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reverse(char ***number, char ***stack_b)
{
	rra_b(number, stack_b);
	write(1, "rra\n", 4);
}

void	sort_3(char ***number, char ***stack_b)
{
	if (ft_last(*number) == 2)
	{
		if ((ft_atoi((*number)[0]) > ft_atoi((*number)[1])))
			swap(number);
	}
	else if (ft_last(*number) == 3)
	{
		if ((ft_atoi((*number)[0]) > ft_atoi((*number)[1])))
		{
			if (ft_atoi((*number)[1]) > ft_atoi((*number)[2]))
				swap_and_reverse(number, stack_b);
			else if (ft_atoi((*number)[0]) > ft_atoi((*number)[2]))
				top_to_bottom(number, stack_b, 1);
			else
				swap(number);
		}
		else
		{
			if (ft_atoi((*number)[0]) > ft_atoi((*number)[2]))
				reverse(number, stack_b);
			else if (ft_atoi((*number)[1]) > ft_atoi((*number)[2]))
				swap_and_back(number, stack_b);
		}
	}
}
