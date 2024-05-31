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

//Main Function
int main(int argc, char *argv[])
{
	char **number;
	char **stack_b;
	int	i = 1;
	int j = 1;
	int len = 0;

	if (argv[1] == NULL || argc == 1)
		return (0);
	if (argc == 2)
	{
		number = ft_split(argv[1], ' ');
		stack_b = ft_calloc(sizeof(char *), argc);
		if (!stack_b)
			return (1);
	}
	else
	{
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

	//swap_first(number); Works and is good
	//pa_b works
	//ra_b(&number); Works

	pa_b(&number, &stack_b);
	ra_b(&number);

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

	if (!stack_b)
		free_array(stack_b);

	return (0);
}
