/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:04:47 by aruckenb          #+#    #+#             */
/*   Updated: 2024/07/19 12:04:51 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_top_loop(int len, int i, char **temp_array, char **example2)
{
	while (i <= len)
	{
		if (example2 == NULL)
			break ;
		temp_array[i] = malloc(ft_strlen(example2[i - 1]) + 1);
		if (!temp_array[i])
		{
			while (i > 0)
				free(temp_array[--i]);
			return (free(temp_array), 0);
		}
		ft_strcpy(temp_array[i], example2[i - 1]);
		i++;
	}
	return (1);
}

char	**push_top(char **example, char **example2)
{
	int		i;
	int		len;
	char	**temp_array;

	i = 0;
	len = length_2d(example2);
	temp_array = (char **)malloc(sizeof(char *) * (len + 2));
	if (!temp_array)
		return (NULL);
	temp_array[i] = malloc(ft_strlen(example[0]) + 1);
	if (!temp_array[i])
		return (free(temp_array), NULL);
	ft_strcpy(temp_array[i], example[0]);
	i++;
	if (len > 0)
	{
		if (push_top_loop(len, i, temp_array, example2) == 0)
			return (NULL);
	}
	temp_array[len + 1] = NULL;
	return (temp_array);
}

char	**push_top_update(char **example)
{
	int		i;
	int		len;
	char	**temp_array;

	i = 0;
	len = length_2d(example);
	temp_array = (char **)malloc(sizeof(char *) * len);
	if (!temp_array)
		return (NULL);
	while (i < len - 1)
	{
		temp_array[i] = malloc(ft_strlen(example[i + 1]) + 1);
		if (!temp_array[i])
		{
			while (i >= 0)
				free(temp_array[i--]);
			return (free(temp_array), NULL);
		}
		ft_strcpy(temp_array[i], example[i + 1]);
		i++;
	}
	temp_array[len - 1] = NULL;
	return (temp_array);
}

void	free_arrays_pa_b(char ***example, char ***example2)
{
	free_array(*example);
	free_array(*example2);
}

void	pa_b(char ***example, char ***example2)
{
	char	**new_example2;
	char	**new_example;

	if (**example == NULL)
		return ;
	new_example2 = push_top(*example, *example2);
	new_example = push_top_update(*example);
	if (new_example && new_example2)
	{
		if (*example2)
			free_array(*example2);
		if (*example)
			free_array(*example);
		*example2 = new_example2;
		*example = new_example;
	}
	else
	{
		free_arrays_pa_b(example, example2);
		if (new_example2)
			free_array(new_example2);
		if (new_example)
			free_array(new_example);
		exit(1);
	}
}
