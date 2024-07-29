/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:06:40 by aruckenb          #+#    #+#             */
/*   Updated: 2024/07/19 12:06:44 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra_b_loop(char **example, char **temp_array, int i, int len)
{
	while (i < len)
	{
		if (i == len - 1)
		{
			temp_array[i] = ft_calloc(sizeof(char),
					ft_strlen(example[0]) + 1);
			if (!temp_array[i])
				return (reverse_free(temp_array, i), 1);
			ft_strcpy(temp_array[i], example[0]);
		}
		else
		{
			temp_array[i] = ft_calloc(sizeof(char),
					ft_strlen(example[i + 1]) + 1);
			if (!temp_array[i])
				return (reverse_free(temp_array, i), 1);
			ft_strcpy(temp_array[i], example[i + 1]);
		}
		i++;
	}
	return (0);
}

char	**first_to_last(char **example)
{
	int		i;
	int		len;
	char	**temp_array;

	i = 0;
	len = length_2d(example);
	temp_array = ft_calloc(sizeof(char *), len + 1);
	if (!temp_array)
		return (NULL);
	if (ra_b_loop(example, temp_array, i, len) == 1)
		return (NULL);
	return (free_array(example), temp_array);
}

void	ra_b(char ***example, char ***example2)
{
	char	**temp;

	temp = first_to_last(*example);
	if (temp)
		*example = temp;
	else
	{
		free_array(*example);
		free_array(*example2);
		exit(1);
	}
}

void	rr(char ***example, char ***example2)
{
	char	**temp;
	char	**temp2;

	temp = first_to_last(*example);
	if (temp)
		*example = temp;
	temp2 = first_to_last(*example2);
	if (temp2)
		*example2 = temp2;
}
