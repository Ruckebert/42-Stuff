/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:26:22 by aruckenb          #+#    #+#             */
/*   Updated: 2024/07/19 12:26:24 by aruckenb         ###   ########.fr       */
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
	int	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	checker(char **array, char **stack_b)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i + 1] == NULL)
			break ;
		if (ft_atoi(array[i]) > ft_atoi(array[i + 1]))
			return ;
		else
			i++;
	}
	free_array(array);
	free_array(stack_b);
	exit(0);
}

void	dup_checker(char **argv, int i, int num)
{
	int	j;

	j = 1;
	while (argv[j])
	{
		if (j == i)
		{
			j++;
			continue ;
		}
		else if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
		{
			if (num == 1)
				free_array(argv);
			exit(write(2, "Error\n", 6));
		}
		j++;
	}
}

void	argv_checker(char **argv, int num)
{
	int		i;
	char	*new;

	i = 0;
	if (num == 1)
		i = -1;
	while (argv[++i])
	{
		new = ft_itoa(ft_atoi(argv[i]));
		if (!new)
		{
			if (num == 1)
				free_array(argv);
			exit(write(2, "Error\n", 6));
		}
		if (ft_strncmp(argv[i], new, ft_strlen(new) + 1))
		{
			if (num == 1)
				free_array(argv);
			free(new);
			exit(write(2, "Error\n", 6));
		}
		free(new);
		dup_checker(argv, i, num);
	}
}
