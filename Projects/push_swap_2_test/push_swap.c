/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:59:21 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/16 13:04:52 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = *src;
	return (start);
}

int	ft_last(char **str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int checker(char **array)
{
	int i;
	i = 0;
	while (array[i])
	{
		if (array[i + 1] == NULL)
			break ;
		if (ft_atoi(array[i]) > ft_atoi(array[i + 1]))
			return (0);
		else
			i++;
	}
	return (1);
}

void argv_checker(char **argv)
{
	int i;
	int j;
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == -2147483648)
			exit(1);
		if(ft_atoi(argv[i]) == -1)
			exit(1);
		j = i - 1;
		while (argv[j])
		{	
			if (argv[j] == argv[i])
				exit(1);
			j--;
		}
		i++;
	}
}

//Main Function
int main(int argc, char *argv[])
{
	char **number;
	char **stack_b;
	int	i = 1;

	if (argv[1] == NULL || argc == 1)
		return (0);
	if (argc == 2)
	{
		number = ft_split(argv[1], ' ');
		argv_checker(number);
		stack_b = ft_calloc(sizeof(char *), argc);
		if (!stack_b)
			return (1);
	}
	else
	{
		argv_checker(argv);
		number = ft_calloc(sizeof(char *), argc + 1);
		if (!number)
			return (1);
		stack_b = ft_calloc(sizeof(char *), argc + 1);
		if (!stack_b)
			return (1);
		while (i < argc)
		{
			number[i - 1] = ft_calloc(sizeof(char), ft_strlen(argv[i]) + 1);
			if (!number[i - 1])
			{
				while (i - 1 > 0)
				{
					free(number[i - 1]);
					i--;
				}
				free(number);
				return (1);
			}
			ft_strcpy(number[i - 1], argv[i]);
			i++;
		}
	}
	
	//Checker Works
	if (checker(number) == 1)
		return (0);
	
	//Have a unique case for hwne the stack has only three elements
	if (ft_last(number) == 3)
		if (sort_3(number) == 1)
			return (ft_printf("DONE"));

	//Five Solution (Not Completed)
	if (ft_last(number) == 5)
	{
		pa_b(&number, &stack_b);
		pa_b(&number, &stack_b);
		sort_3(number);
		pa_b(&stack_b, &number);
		pa_b(&stack_b, &number);
	}

	//Algorithem (Need a new solution)
	i = 0;
	int size = ft_last(number); 
	//int count = 0;

	//First Placement
	int placement = 0;

	//Second Placement
	int placement2 = 0;

	//each chunk increases by +20
	int placement1 = 0;
	int chunk_size = 0;

	//int chunk1 = abs((ft_last(number)/2) - 0);
	//int chunk1 = ft_last(number)/2 - 10;
	//int chunk2 = (ft_last(number)/2) + 10;
	//int chunk2 = ft_last(number);
	int chunk1 = 0;
	int chunk2 = 19;

	placement1 = 0;

	//This part checks whther or not you use ra_b or rra_b (Step 2/3)
	//I found out that the checkersort only takes more moves but is correct
	//Where as only placement is less moves but the stacks or not sorted
	while (chunk_size <= 3)
	{
		i = 0;
		while (i <= chunk2/2)
		{
			placement  = loop_forward(number, chunk1, chunk2);
			
			if (placement > 0)
				first_position(&number, placement);
			pa_b(&number, &stack_b);
			write(1, "pb\n", 3);

			/*placement1 = stack_organ(stack_b);
			sort_placement(placement1, &stack_b, 2);*/

			while(checker(stack_b) == 0)
				checker_sort(&stack_b);

			placement2 = loop_back(number, chunk1, chunk2);
			first_position(&number, placement2);
			pa_b(&number, &stack_b);
			write(1, "pb\n", 3);

			/*placement1 = stack_organ(stack_b);
			sort_placement(placement1, &stack_b, 2);*/

			while(checker(stack_b) == 0)
				checker_sort(&stack_b);
			if (checker(stack_b) == 1 && ft_last(number) == 0)
				break ;
			i++;

			/*
			placement  = loop_forward(number, chunk1, chunk2);
			if (placement > 0)
				first_position(&number, placement);
			int j = 0;
			while (stack_b[j])
			{	
				if (ft_atoi(number[0]) > ft_atoi(stack_b[j + 1]))
					j++;
				else
					break ;
			}
			if (j == ft_last(stack_b))
			{
				pa_b(&number, &stack_b);
				write(1, "pb\n", 3);
				rra_b(&stack_b);
			}
			placement = stack_organ(stack_b);
			placement2 = loop_back(number, chunk1, chunk2);
			first_position(&number, placement2);*/
		}
		if (checker(stack_b) == 1 && ft_last(number) == 0)
			break ;
		chunk1 += 10;
		chunk2 += 10;
		chunk_size++;
	}

	//This while loop is the cause of the huge amount of moves
	/*while (1)
	{
		if (checker(stack_b) == 0)
			checker_sort(&stack_b);
		else
			break ;
	}*/

	i = 0;
	size = ft_last(stack_b);
	while (i < size)
	{
		rra_b(&stack_b);
		write(1, "rrb\n", 4);
		pa_b(&stack_b, &number);
		write(1, "pa\n", 3);
		i++;
	}

	if (checker(number) == 1)
	{
		free_array(number);
		free_array(stack_b);
		return (0);
	}

	//Freeing
	free_array(number);
	free_array(stack_b);

	return (0);
}
