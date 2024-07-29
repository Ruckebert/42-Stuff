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

int	stack_a(int argc, char *argv[], char ***number, char ***stack_b)
{
	int	i;

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
	return (0);
}

void	sort_arrays(char **arr1, char **arr2, int i)
{
	char	*temp;
	int		swapped;

	while (1)
	{
		swapped = 0;
		i = 0;
		while (arr1[i + 1])
		{
			if (ft_atoi(arr1[i]) > ft_atoi(arr1[i + 1]))
			{
				temp = arr1[i];
				arr1[i] = arr1[i + 1];
				arr1[i + 1] = temp;
				temp = arr2[i];
				arr2[i] = arr2[i + 1];
				arr2[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break ;
	}
}

char	**convert_to_indexes(char **number, int argc)
{
	char	**indexes;
	char	**temp;
	int		i;

	i = 0;
	indexes = ft_calloc(sizeof(char *), argc);
	if (!indexes)
		return (free(indexes), NULL);
	temp = ft_calloc(sizeof(char *), argc);
	if (!temp)
		return (free(indexes), free(temp), NULL);

	while (i < argc - 1)
	{
		indexes[i] = ft_itoa(i + 1);
		if (!indexes)
			return (reverse_free(indexes, i), reverse_free(indexes, i), NULL);
		temp[i] = ft_itoa(i + 1);
		if (!indexes)
			return (reverse_free(temp, i), reverse_free(indexes, i), NULL);
		i++;
	}
	sort_arrays(number, temp , i);
	sort_arrays(temp, indexes, i);
	return (free_array(number), free_array(temp), indexes);
}

int	main(int argc, char *argv[])
{
	char	**number;
	char	**stack_b;
	char	**indexes;

	number = NULL;
	stack_b = NULL;
	if (argv[1] == NULL || argc == 1)
		return (0);
	if (argc == 2)
	{
		number = ft_split(argv[1], ' ');
		if (!number)
			return (1);
		argv_checker(number, 1);
		stack_b = ft_calloc(sizeof(char *), argc);
		if (!stack_b)
			return (free_array(number), 1);
	}
	else
	{
		argv_checker(argv, 0);
		if (stack_a(argc, argv, &number, &stack_b) == 1)
			return (1);
	}
	sort_3(&number, &stack_b);
	indexes = convert_to_indexes(number, argc);
	if (!indexes)
		return (free_array(number), free_array(stack_b), 0);
	algorthim(indexes, stack_b);
}
