/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:08:13 by aruckenb          #+#    #+#             */
/*   Updated: 2024/07/19 12:08:15 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra_b_loop(char **example, char **temp_array, int i, int len)
{
	while (i < len)
	{
		if (i == 0)
		{
			temp_array[i] = ft_calloc(sizeof(char),
					ft_strlen(example[len - 1]) + 1);
			if (!temp_array[i])
				return (reverse_free(temp_array, i), 1);
			ft_strcpy(temp_array[i], example[len - 1]);
		}
		else
		{
			temp_array[i] = ft_calloc(sizeof(char),
					ft_strlen(example[i - 1]) + 1);
			if (!temp_array[i])
				return (reverse_free(temp_array, i), 1);
			ft_strcpy(temp_array[i], example[i - 1]);
		}
		i++;
	}
	return (0);
}

char	**last_to_first(char **example)
{
	int		i;
	int		len;
	char	**temp_array;

	i = 0;
	len = length_2d(example);
	temp_array = ft_calloc(sizeof(char *), len + 1);
	if (!temp_array)
		return (NULL);
	if (rra_b_loop(example, temp_array, i, len) == 1)
		return (NULL);
	return (free_array(example), temp_array);
}

void	rra_b(char ***example, char ***example2)
{
	char	**temp;

	temp = last_to_first(*example);
	if (temp)
		*example = temp;
	else
	{
		free_array(*example);
		free_array(*example2);
		exit(1);
	}
}

void	rrr(char ***example, char ***example2)
{
	*example = last_to_first(*example);
	*example2 = last_to_first(*example2);
}

int	loop_forward(char **number, int chunk1, int chunk2)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (ft_atoi(number[i]) >= chunk1 && ft_atoi(number[i]) <= chunk2)
			return (i);
		i++;
	}
	return (0);
}
