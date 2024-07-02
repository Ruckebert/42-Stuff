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

int sort_3(char **number)
{
	if ((ft_atoi(number[0]) > ft_atoi(number[1])))
	{
		if (ft_atoi(number[1]) > ft_atoi(number[2]))
		{
			swap_first(number);
			rra_b(&number);
		}
		else if (ft_atoi(number[0]) > ft_atoi(number[2]))
			ra_b(&number);
		else
			swap_first(number);
	}
	else
	{
		if (ft_atoi(number[0]) > ft_atoi(number[2]))
		{
			swap_first(number);
			rra_b(&number);
		}
		else if (ft_atoi(number[1]) > ft_atoi(number[2]))
				ra_b(&number);
	}
	if (checker(number) == 1)
		return (1);
	return (0);
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

void first_position(char **number, int placement, char *temp)
{
	int j = 0;
	int iterations = 0;
	int size = ft_last(number) + 1;
	j = size / 2;

	if (placement <= j)
	{	
		while (ft_atoi(number[0]) != ft_atoi(temp) && iterations < size)
		{
			ra_b(&number);
			iterations++;
		}
	}
	else
	{
		while (ft_atoi(number[0]) != ft_atoi(temp) && iterations < size) 
		{
			rra_b(&number);
			iterations++;
		}
	}
}

int stack_organ(char **stack_b)
{
	int i = 1;
	int last_index = ft_last(stack_b);

	if (checker(stack_b) == 1)
		return (0);
	if (last_index == 2)
	{
		if (ft_atoi(stack_b[0]) > ft_atoi(stack_b[last_index - 1]))
			swap_first(stack_b);
		return (0);
	}
	else
	{
		while (i < last_index)
		{
			if (ft_atoi(stack_b[0]) > ft_atoi(stack_b[i]))
				i++;
			else if (ft_atoi(stack_b[0]) < ft_atoi(stack_b[i]))
				return (i);
		}
	}
	return (i);
}

void sort_placement(int placement, char ***stack_b)
{
	int i;

	i = 0;
	if (placement == 0)
		return ;
	if (placement == 2)
		swap_first(*stack_b);
	else if (placement == ft_last(*stack_b))
		ra_b(stack_b);
	else if (placement == ft_last(*stack_b) - 1)
	{
		rra_b(stack_b);
		swap_first(*stack_b);
		ra_b(stack_b);
		ra_b(stack_b);
	}
	else if (placement > 2 && placement < ft_last(*stack_b) - 1)
	{	
		if (placement <= ft_last(*stack_b)/2)
		{
			while (i <= placement/2)
			{
				swap_first(*stack_b);
				ra_b(stack_b);
				i++;
			}
			i = 0;
			while (i <= placement/2)
			{
				rra_b(stack_b);
				i++;
			}
		}
		else if (placement > ft_last(*stack_b)/2)
		{	
			if (placement == ft_last(*stack_b)/2 + 1)
			{
				rra_b(stack_b);
				swap_first(*stack_b);
			}
			while (i < placement/2)
			{
				rra_b(stack_b);
				swap_first(*stack_b);
				i++;
			}
			i = 0;
			while (i <= placement/2)
			{
				ra_b(stack_b);
				i++;
			}
			if (placement == ft_last(*stack_b)/2 + 1)
				ra_b(stack_b);
		}
	}
}