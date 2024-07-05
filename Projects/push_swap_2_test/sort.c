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

void first_position(char ***number, int placement)
{
	int j = 0;
	int size = ft_last(*number);
	if (ft_last(*number) == 1)
		return ;
	char *temp;
	temp = (*number)[placement];
	j = size / 2;
	if (placement <= j)
	{	
		while (placement != 0)
		{
			ra_b(number);
			write(1, "ra\n", 3);
			placement--;
		}
	}
	else if (placement > j)
	{
		placement = (size - placement);
		while (placement != 0)
		{
			rra_b(number);
			write(1, "rra\n", 4);
			placement--;
		}
	}
}

int stack_organ(char **stack_b)
{
	int i = 1;
	int last_index = ft_last(stack_b);

	if (checker(stack_b) == 1)
		return (0);
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

void sort_placement(int placement, char ***stack_b, int num)
{
	int i;
	int size = ft_last(*stack_b);

	i = 0;
	if (placement == 0)
		return ;
	if (placement == 2)
	{
		swap_first(*stack_b);
		if (num == 1)
			write(1, "sa\n", 3);
		else 
			write(1, "sb\n", 3);
	}
	else if (placement == size)
	{
		ra_b(stack_b);
		if (num == 1)
			write(1, "ra\n", 3);
		else 
			write(1, "rb\n", 3);
	}
	else if (placement == size - 1)
	{
		rra_b(stack_b);
		if (num == 1)
			write(1, "rra\n", 4);
		else 
			write(1, "rrb\n", 4);
		swap_first(*stack_b);
		if (num == 1)
			write(1, "sa\n", 3);
		else 
			write(1, "sb\n", 3);
		ra_b(stack_b);
		if (num == 1)
			write(1, "ra\n", 3);
		else 
			write(1, "rb\n", 3);
		ra_b(stack_b);
		if (num == 1)
			write(1, "ra\n", 3);
		else 
			write(1, "rb\n", 3);
	}
	else if (placement > 2 && placement < size - 1)
	{	
		if (placement <= size/2)
		{
			while (i <= placement/2)
			{
				swap_first(*stack_b);
				if (num == 1)
					write(1, "sa\n", 3);
				else 
					write(1, "sb\n", 3);
				ra_b(stack_b);
				if (num == 1)
					write(1, "ra\n", 3);
				else 
					write(1, "rb\n", 3);
				i++;
			}
			i = 0;
			while (i <= placement/2)
			{
				rra_b(stack_b);
				if (num == 1)
					write(1, "rra\n", 4);
				else 
					write(1, "rrb\n", 4);
				i++;
			}
		}
		else if (placement > size/2)
		{	
			if (placement == size/2 + 1)
			{
				rra_b(stack_b);
				if (num == 1)
					write(1, "rra\n", 4);
				else 
					write(1, "rrb\n", 4);
				swap_first(*stack_b);
				if (num == 1)
					write(1, "sa\n", 3);
				else 
					write(1, "sb\n", 3);
			}
			while (i < placement/2)
			{
				rra_b(stack_b);
				if (num == 1)
					write(1, "rra\n", 4);
				else 
					write(1, "rrb\n", 4);
				swap_first(*stack_b);
				if (num == 1)
					write(1, "sa\n", 3);
				else 
					write(1, "sb\n", 3);
				i++;
			}
			i = 0;
			while (i <= placement/2)
			{
				ra_b(stack_b);
				if (num == 1)
					write(1, "ra\n", 3);
				else 
					write(1, "rb\n", 3);
				i++;
			}
			if (placement == size/2 + 1)
			{
				ra_b(stack_b);
				if (num == 1)
					write(1, "ra\n", 3);
				else 
					write(1, "rb\n", 3);
			}
		}
	}
}

void checker_sort(char ***stack_b)
{
	int j = 0;
	int placement;
	int place;
	int temp_place;
	//int size = ft_last(*stack_b);

	while ((*stack_b)[j])
	{	
		if (ft_atoi((*stack_b)[j]) < ft_atoi((*stack_b)[j + 1]))
			j++;
		else
			break ;
	}
	placement = j;

	j = 0;
	while (j < ft_last(*stack_b))
	{
		if (ft_atoi((*stack_b)[placement]) >= ft_atoi((*stack_b)[j]))
			j++;
		else
			break ;
	}

	place = j - placement;
	if (placement < ft_last(*stack_b)/2)
	{
		temp_place = placement;
		while (placement > 0) 
		{
				ra_b(stack_b);
				write(1, "rb\n", 3);
				placement--;
		}
		sort_placement(place, stack_b, 2);
		while (temp_place > 0)
		{
			rra_b(stack_b);
			write(1, "rrb\n", 4);
			temp_place--;
		}
	}
	else 
	{
		placement = (ft_last((*stack_b)) - placement);
		temp_place = placement;
		while (placement > 0) 
		{
				rra_b(stack_b);
				write(1, "rb\n", 3);
				placement--;
		}
		sort_placement(place, stack_b, 2);
		while (temp_place > 0)
		{
			ra_b(stack_b);
			write(1, "rrb\n", 4);
			temp_place--;
		}
	}
}