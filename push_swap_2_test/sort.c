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

void swap_and_reverse(char ***number)
{
	swap_first(*number);
	write(1, "sa\n", 3);
	rra_b(number, NULL);
	write(1, "rra\n", 4);
}

void top_to_bottom(char ***number, char ***stack_b, int i)
{
	ra_b(number, stack_b);
	if (i == 1)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}
void sort_3(char ***number, char ***stack_b)
{
	if (ft_last(*number) == 3)
	{
		if ((ft_atoi((*number)[0]) > ft_atoi((*number)[1])))
		{
			if (ft_atoi((*number)[1]) > ft_atoi((*number)[2]))
				swap_and_reverse(number);
			else if (ft_atoi((*number)[0]) > ft_atoi((*number)[2]))
				top_to_bottom(number, NULL, 1);
			else
			{
				swap_first(*number);
				write(1, "sa\n", 3);
			}
		}
		else
		{
			if (ft_atoi((*number)[0]) > ft_atoi((*number)[2]))
				swap_and_reverse(number);
			else if (ft_atoi((*number)[1]) > ft_atoi((*number)[2]))
				top_to_bottom(number, NULL, 1);
		}
		checker(*number, *stack_b);
	}
}

int	loop_forward(char **number, int chunk1, int chunk2)
{
	int i;
	i = 0;
	while (number[i])
	{
		if (ft_atoi(number[i]) >= chunk1 && ft_atoi(number[i]) <= chunk2)
			return (i);
		i++;
	}
	return (0);
}

int	loop_back(char **number, int chunk1, int chunk2)
{
	int i;
	i = 0;
	while (number[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (ft_atoi(number[i]) >= chunk1 && ft_atoi(number[i]) <= chunk2)
			return (i);
		i--;
	}
	return (0);
}
