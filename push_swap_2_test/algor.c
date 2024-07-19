/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:31:03 by aruckenb          #+#    #+#             */
/*   Updated: 2024/07/19 12:31:18 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void first_push(int chunk1, int chunk2, char ***number, char ***stack_b)
{
	int placement;
	int placement2;
	int i;

	placement = placement2 = 0;
	i = chunk1;
	while (i++ < chunk2)
	{
		placement  = loop_forward(*number, chunk1, chunk2);
		placement2 = loop_back(*number, chunk1, chunk2);
		if ((ft_last(*number) - placement2) > placement)
		{
			if (placement > 0) 
				first_position(number, stack_b, placement, 1);
			sort_placement(stack_b, number, ft_last(*stack_b));
		}
		else
		{
			first_position(number, stack_b, placement2, 1);
			sort_placement(stack_b, number, ft_last(*stack_b));
		}
		if (ft_last(*number) == 0)
			return ;
	}
}

void first_push_stack_a(char ***stack_b, char ***number)
{
	int placement;

	placement = 0;
	placement = stack_organ(*stack_b);
	if (placement > 0)
		first_position(stack_b, stack_b, placement, 0);
	pa_b(stack_b, number);
	write(1, "pa\n", 3);
}

int next_number(char ***stack_b, int i)
{
	int big_temp;
	int size;

	size = ft_last(*stack_b) - 1;
	if (i == size)
	{
		big_temp = 0;
		i = 0;
		while (i < size)
		{
			if ((*stack_b)[i + 1] == NULL)
				break ;
			if (ft_atoi((*stack_b)[big_temp]) < ft_atoi((*stack_b)[i + 1]))
				big_temp = i + 1;
			i++;
		}
		return (big_temp);
	}
	return (0);
}

void final_sort(char ***number, char ***stack_b)
{
	int big_temp; 
	int i;

	big_temp = 1;
	while (ft_last(*stack_b) != 0)
	{
		if ((ft_atoi((*number)[0]) - 1) == ft_atoi((*stack_b)[0]))
			push_write(stack_b, number, 1);
		else
		{
			i = 0;
			while (i < ft_last(*stack_b) - 1 && (ft_atoi((*number)[0]) - 1) != ft_atoi((*stack_b)[i]))
				i++;
			big_temp = next_number(stack_b, i);
			if (big_temp != 0)
			{
				first_position(stack_b, number, big_temp, 0);
				push_write(stack_b, number, 1);
			}
			else
				first_position(stack_b, number, i, 0);
		}
	}
}
void algorthim(char **number, char **stack_b)
{
	int size = ft_last(number); 
	int over_all_size = 0;
	int chunk_size = 0;
	int chunk1 = 0;
	int chunk2 = 20;

	if (size <= 10)
		over_all_size = 1;
	else
		over_all_size = (size/20) + 1;
	while (chunk_size++ <= over_all_size)
	{
		first_push(chunk1, chunk2, &number, &stack_b);
		if (ft_last(number) == 0)
			break ;
		chunk1 += 20;
		chunk2 += 20;
	}
	first_push_stack_a(&stack_b, &number);
	final_sort(&number, &stack_b);
	checker(number, stack_b);
}