/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:51:08 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/30 14:51:10 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	length_2d(char **example)
{
	int	i;

	i = 0;
	if (!example)
		return (2);
	while (example[i])
		i++;
	return (i);
}

void	free_array(char **example)
{
	int	i;

	i = 0;
	if (example)
	{
		while (example[i])
		{
			free(example[i]);
			i++;
		}
		free(example);
	}
}

void	swap_first(char **example)
{
	char	*temp;

	temp = example[0];
	example[0] = example[1];
	example[1] = temp;
}

void	swap_double(char **example, char **example2)
{
	swap_first(example);
	swap_first(example2);
}

void	reverse_free(char **temp_array, int i)
{
	while (i >= 0)
		free(temp_array[i--]);
	free(temp_array);
}
