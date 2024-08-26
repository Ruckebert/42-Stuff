/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:25:18 by aruckenb          #+#    #+#             */
/*   Updated: 2024/07/19 12:25:23 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_write(char ***stack_b, char ***number, int i)
{
	pa_b(stack_b, number);
	if (i == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	first_position(char ***number, char ***stack_b, int placement, int num)
{
	if (ft_last(*number) == 1)
		return ;
	if (placement <= (ft_last(*number) / 2))
	{
		while (placement-- != 0)
			top_to_bottom(number, stack_b, num);
	}
	else if (placement > (ft_last(*number) / 2))
	{
		placement = ((ft_last(*number)) - placement);
		while (placement-- != 0)
		{
			rra_b(number, stack_b);
			if (num == 1)
				write(1, "rra\n", 4);
			else
				write(1, "rrb\n", 4);
		}
	}
}

int	stack_organ(char **stack_b)
{
	int	j;
	int	i;
	int	last_index;

	last_index = ft_last(stack_b);
	i = 1;
	j = 0;
	while (i < last_index)
	{
		if (ft_atoi(stack_b[j]) > ft_atoi(stack_b[i]))
			i++;
		else
		{
			j = i;
			i = 1;
		}
	}
	return (j);
}

void	sort_placement(char ***stack_b, char ***number, int size)
{
	if ((*stack_b)[0] == NULL)
		push_write(number, stack_b, 0);
	else if (ft_atoi((*number)[0]) < ft_atoi((*stack_b)[size - 1]))
	{
		push_write(number, stack_b, 0);
		top_to_bottom(stack_b, number, 0);
	}
	else if (ft_last(*stack_b) > 1
		&& ft_atoi((*number)[0]) < ft_atoi((*stack_b)[0]))
	{
		push_write(number, stack_b, 0);
		swap_first(*stack_b);
		write(1, "sb\n", 3);
	}
	else if (size > 1 && ft_atoi((*number)[0]) < ft_atoi((*stack_b)[size - 2]))
	{
		rra_b(stack_b, number);
		write(1, "rrb\n", 4);
		push_write(number, stack_b, 0);
		top_to_bottom(stack_b, number, 0);
		top_to_bottom(stack_b, number, 0);
	}
	else
		push_write(number, stack_b, 0);
}

int	loop_back(char **number, int chunk1, int chunk2)
{
	int	i;

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
