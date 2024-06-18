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
			return (1);
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
		argv_checker(number); //Check if this works
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
		stack_b = ft_calloc(sizeof(char *), argc);
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
	//Seperated 
	//This one works but the combined one doesnt IDK why
	if (ft_last(number) == 3)
	{
		//Case 1
		if ((ft_atoi(number[0]) > ft_atoi(number[1])))
		{
			if (ft_atoi(number[0]) < ft_atoi(number[2]))
				swap_first(number);
		}
		//Case 2
		if ((ft_atoi(number[0]) > ft_atoi(number[1])))
		{
			if (ft_atoi(number[0]) > ft_atoi(number[2]))
			{
				if (ft_atoi(number[1]) > ft_atoi(number[2]))
				{
					swap_first(number);
					rra_b(&number);
				}
			}
		}
		//Case 3
		if ((ft_atoi(number[0]) > ft_atoi(number[1])))
		{
			if (ft_atoi(number[0]) > ft_atoi(number[2]))
			{
				if (ft_atoi(number[1]) < ft_atoi(number[2]))
					ra_b(&number);
			}
		}
		//Case 4
		if ((ft_atoi(number[0]) < ft_atoi(number[1])))
		{
			if (ft_atoi(number[0]) < ft_atoi(number[2]))
			{
				if (ft_atoi(number[1]) > ft_atoi(number[2]))
				{
					swap_first(number);
					ra_b(&number);
				}

			}
		}
		//Case 5
		if ((ft_atoi(number[0]) < ft_atoi(number[1])))
		{
			if (ft_atoi(number[0]) > ft_atoi(number[2]))
				rra_b(&number);
		}
		if (checker(number) == 1)
			return (printf("DONE"));

	}

	//Combined
	//For some reason didnt work with lager numbers (Doesnt work)
	/*
	if (ft_last(number) == 3)
	{
		if ((ft_atoi(number[0]) > ft_atoi(number[1])))
		{
			if (ft_atoi(number[0]) < ft_atoi(number[2]))
				swap_first(number);
			else
			{
				if (ft_atoi(number[1]) > ft_atoi(number[2]))
				{
					swap_first(number);
					rra_b(&number);
				}
				else 
					ra_b(&number);
			}
		}
		else
		{
			if (ft_atoi(number[0]) < ft_atoi(number[2]))
			{
				if (ft_atoi(number[1]) > ft_atoi(number[2]))
				{
					swap_first(number);
					ra_b(&number);
				}
				else
					rra_b(&number);
			}
		}
	}*/

	//Five Solution (Not Completed)
	if (ft_last(number) == 5)
	{
		int correct = 0;
		pa_b(&number, &stack_b);
		pa_b(&number, &stack_b);
		while (correct != 1) // Change this one to the one that works
		{
			if ((ft_atoi(number[0]) > ft_atoi(number[1])))
			{
				if (ft_atoi(number[0]) < ft_atoi(number[2]))
					swap_first(number);
				else
				{
					if (ft_atoi(number[1]) > ft_atoi(number[2]))
					{
						swap_first(number);
						rra_b(&number);
					}
					else 
						ra_b(&number);
				}
			}
			else
			{
				if (ft_atoi(number[0]) < ft_atoi(number[2]))
				{
					if (ft_atoi(number[1]) > ft_atoi(number[2]))
					{
						swap_first(number);
						ra_b(&number);
					}
					else
						rra_b(&number);
				}
			}
			if (checker(number) == 1)
				correct = 1;
		}
		correct = 0;
		if (stack_b[0] < stack_b[1])
			pa_b(&stack_b, &number);
		else
		{
			swap_first(stack_b);
			pa_b(&stack_b, &number);
		}
		i = 1;
		while (correct != 1)
		{
			if ((ft_atoi(number[0]) > ft_atoi(number[i])))
			{

			}
			if (checker(number) == 1)
				correct = 1;
		}
		/*
		if (ft_atoi(number[0]) > ft_atoi(number[ft_last(number) - 1]))
			ra_b(&number);
		else
			write(1, "1", 1);//While LOop
		*/

	}

	//Algorithem (Need a new solution)

	i = 0;
	int j = 0;

	//First Placement
	int placement = 0;
	char *temp = NULL;

	//Second Placement
	int placement2 = 0;
	char *temp2 = NULL;
	temp = number[i];

	while (number[i])
	{	//Saves the first number from the first chunk
		if (ft_atoi(number[i]) >= 0 && ft_atoi(number[i]) <= 19)
		{
			placement = i;
			temp = number[i];
			break ;
		}
	}

	//Finishes the loop
	while (number[i])
		i++;

	while (i > 0)
	{	//Saves the second number from the first chunk but backwards
		if (ft_atoi(number[i]) >= 0 && ft_atoi(number[i]) <= 19)
		{
			placement2 = i;
			temp2 = number[i];
			break ;
		}
		i--;
	}

	//Gets the list size halfed 
	j = ft_last(number);
	j /= 2;

	//This part checks whther or not you use ra_b or rra_b 
	if (placement <= j)
	{
		while (ft_atoi(number[0]) != ft_atoi(temp))
			ra_b(&number);
	}
	else 
	{
		while (ft_atoi(number[0]) != ft_atoi(temp))
			rra_b(&number);
	}

	//Sorting the Stack to make it in order (Step 4)
	int correct = 0;
	while (correct != 1)
	{
		if (number[i] < number[i + 1])
		{
			write(1, "FUCK", 4);
		}
		if (checker(number) == 1)
			correct = 1;
	}

	//Pushes the number into the stack_b
	//Kinda redondent in theory cause the stack should already be orgainzed 
	if (ft_atoi(number[0]) > ft_atoi(stack_b[0]))
	{
		if (ft_atoi(number[0]) > ft_atoi(stack_b[ft_last(stack_b) - 1]))
		{
			pa_b(&number, &stack_b);
			ra_b(&stack_b);
		}
	}
	pa_b(&number, &stack_b);
	//Check if theirs one element or no elements when doing commands
	//Things that you should do ^

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

	//Freeing
	free_array(number);
	free_array(stack_b);

	return (0);
}
