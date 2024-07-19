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

int stack_a(int argc, char *argv[], char ***number, char ***stack_b)
{
	int i;

	i = 0;
	*number = ft_calloc(sizeof(char *), argc + 1);
	if (!(*number))
		return (1);
	*stack_b = ft_calloc(sizeof(char *), argc + 1);
	if (!(*stack_b))
		return (free_array(*number), 1);
	while (++i < argc)
	{
		(*number)[i - 1] = ft_calloc(sizeof(char), ft_strlen(argv[i]) + 1);
		if (!(*number)[i - 1])
		{
			while (i - 1 >= 0)
			{
				free((*number)[i - 1]);
				i--;
			}
			return (free(*number), free(*stack_b), 1);
		}
		ft_strcpy((*number)[i - 1], argv[i]);
	}
	checker(*number, *stack_b);
	return (0);
}

int main(int argc, char *argv[])
{
	char **number;
	char **stack_b;

	number = stack_b = NULL;
	if (argv[1] == NULL || argc == 1)
		return (0);
	if (argc == 2)
	{
		number = ft_split(argv[1], ' ');
		if(!number)
			return (1);
		argv_checker(number);
		stack_b = ft_calloc(sizeof(char *), argc);
		if (!stack_b)
			return (free_array(number), 1);
	}
	else
	{
		argv_checker(argv);
		if (stack_a(argc, argv, &number, &stack_b) == 1)
			return (1);
	}
	sort_3(&number, &stack_b);
	algorthim(number, stack_b);
	return (0);
}
