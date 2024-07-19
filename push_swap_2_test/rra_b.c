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

int rra_b_loop(char **example, char **temp_array, int i, int len)
{
    while (i < len)
	{
		if (i == 0)
		{
			temp_array[i] = ft_calloc(sizeof(char), ft_strlen(example[len - 1]) + 1);
			if (!temp_array[i])
			{
				reverse_free(temp_array, i);
				return (1);
			}
			ft_strcpy(temp_array[i], example[len - 1]);
		}
		else
		{
			temp_array[i] = ft_calloc(sizeof(char), ft_strlen(example[i - 1]) + 1);
			if (!temp_array[i])
			{
				reverse_free(temp_array, i);
				return (1);
			}
			ft_strcpy(temp_array[i], example[i - 1]);
		}
		i++;
	}
	return (0);
}

// RRa/RRb - is the reverse of Ra or Rb (Pushes the last element into the first position)
char **last_to_first(char **example)
{
    int i;
	int len;
	char **temp_array;

	i = 0;
	len = length_2D(example);
	temp_array = ft_calloc(sizeof(char *), len + 1);
	if (!temp_array)
		return (NULL);
	if (rra_b_loop(example, temp_array, i, len) == 1)
		return (NULL);
	return (free_array(example), temp_array);
}

// RRa/RRn
void rra_b(char ***example, char ***example2)
{
	char **temp;

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

// RRR - Does RRa and RRb at the same time 
void rrr(char ***example, char ***example2)
{
	*example = last_to_first(*example);
	*example2 = last_to_first(*example2);
}
