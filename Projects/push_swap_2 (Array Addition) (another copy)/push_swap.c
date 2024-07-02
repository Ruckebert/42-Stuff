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
		return (printf("OK"));
	
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

	//First Placement
	int placement = 0;
	char *temp = NULL;

	//Second Placement
	int placement2 = 0;
	char *temp2 = NULL;

	//each chunk increases by +20
	int chunk1 = 0;
	int chunk2 = 19;

	//This part checks whther or not you use ra_b or rra_b (Step 2/3)
	while (i < size/2)
	{
		placement  = loop_forward(number, chunk1, chunk2);
		temp = number[placement];

		first_position(number, placement, temp);
		pa_b(&number, &stack_b);

		placement = stack_organ(stack_b);
		sort_placement(placement, &stack_b);

		placement2 = loop_back(number, chunk1, chunk2);
		temp2 = number[placement2];

		first_position(number, placement2, temp2);
		pa_b(&number, &stack_b);

		placement = stack_organ(stack_b);
		sort_placement(placement, &stack_b);

		i++;
	}

	if (checker(stack_b) == 0)
	{
		i = 0;
		while (i < size)
		{	
			if (ft_atoi(stack_b[i]) < ft_atoi(stack_b[i + 1]))
				i++;
			else
				break ;
		}
		printf("Stack failure:%s\n", stack_b[i]);
	}


	if (ft_last(number) == placement && placement2 == 0)
	{
		chunk1 += 20;
		chunk2 += 20;
	}


	i = 0;
	size = ft_last(stack_b);
	while (i < size)
	{
		rra_b(&stack_b);
		pa_b(&stack_b, &number);
		i++;
	}

	pa_b(&stack_b, &number);

	//Prints all the numbers (Stack A)
	i = 0;
	printf("Stack A:\n");
	while (number[i] != NULL)
	{
		printf("%s\n", number[i]);
		i++;
	}

	//Prints all the numbers (Stack B)
	i = 0;
	printf("Stack B:\n");
	while (stack_b[i] != NULL)
	{
		printf("%s\n", stack_b[i]);
		i++;
	}

	if (checker(number) == 1)
	{
		free_array(number);
		free_array(stack_b);
		return (printf("OK"));
	}

	//Freeing
	free_array(number);
	free_array(stack_b);

	return (0);
}
