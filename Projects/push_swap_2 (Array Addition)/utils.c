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

int length_2D(char **example)
{
    int i = 0;
	if (!example)
		return (2);
    while (example[i])
        i++;
    return (i);
}

void free_array(char **example)
{
	int i;	
	i = 0;
	while (example[i])
	{
		free(example[i]);
		i++;
	}
	free(example);
}

// Pa/Pb - Push one element on the top
char **push_top(char **example, char **example2)
{
    int i = 0;
	int len = length_2D(example2);
	char **temp_array = (char **)malloc(sizeof(char *) * (len + 2));
	if (!temp_array)
		return (NULL);
	temp_array[i] = malloc(ft_strlen(example[0]) + 1);
	if (!temp_array[i])
	{
		free(temp_array);
		return (NULL);
	}
	ft_strcpy(temp_array[i], example[0]);
	i++;
	if (len > 0)
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
				free(temp_array);
				return (0);
			}
			ft_strcpy(temp_array[i], example2[i - 1]);
			i++;
		}
	}
	temp_array[len + 1] = NULL;
    return (temp_array);
}

// Push top New String old
char **push_top_update(char **example)
{
    int i = 0;
	int len = length_2D(example);
	char **temp_array = (char **)malloc(sizeof(char *) * len);
	if (!temp_array)
		return (NULL);
	
    while (i < len - 1)
	{
        temp_array[i] = malloc(ft_strlen(example[i + 1]) + 1);
		if (!temp_array[i])
		{
			while (i > 0)
				free(temp_array[--i]);
			free(temp_array);
			return (0);
		}
        ft_strcpy(temp_array[i], example[i + 1]);
		i++;
	}
	temp_array[len - 1] = NULL;
    return (temp_array);
}

// the PA/PB function
void pa_b(char ***example, char ***example2)
{
	char **new_example2;
	char **new_example;

    new_example2 = push_top(*example, *example2); //Program crashes here
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
		if (new_example2)
			free_array(new_example2);
		if (new_example)
			free_array(new_example);
	}
}

// Sa/Sb Swaping the first and second element of the array
void swap_first(char **example)
{
    char *temp;

    temp = example[0];
	example[0] = example[1];
	example[1] = temp;
}

// SS
void swap_double(char **example, char **example2)
{
    swap_first(example);
    swap_first(example2);
}

// Ra/Rb - Pushes the first element onto the last element (Function) 
char **first_to_last(char **example)
{
    int i = 0;
	int len = length_2D(example);
	char **temp_array = ft_calloc(sizeof(char *), len + 1);
	if (!temp_array)
		return (NULL);
	
    while (i < len)
	{
		if (i == len - 1)
		{
			temp_array[i] = ft_calloc(sizeof(char), ft_strlen(example[0]) + 1);
			if (!temp_array[i])
			{
				while (i >= 0)
				{
					free(temp_array[i]);
					i--;
				}
				free(temp_array);
				return (NULL);
			}
			ft_strcpy(temp_array[i], example[0]);
		}
		else
		{
			temp_array[i] = ft_calloc(sizeof(char), ft_strlen(example[i + 1]) + 1);
			if (!temp_array[i])
			{
				while (i >= 0)
				{
					free(temp_array[i]);
					i--;
				}
				free(temp_array);
				return (NULL);
			}
			ft_strcpy(temp_array[i], example[i + 1]);
		}
		i++;
	}
	return (temp_array);
}

// Ra/Rb
void ra_b(char ***example)
{
	*example = first_to_last(*example);
}

// RR - Does Ra and Rb at the same time
void rr(char ***example, char ***example2)
{
	*example = first_to_last(*example);
	*example2 = first_to_last(*example2);
}

// RRa/RRb - is the reverse of Ra or Rb
char **last_to_first(char **example)
{
    int i = 0;
	int len = length_2D(example);
	char **temp_array = ft_calloc(sizeof(char *), len + 1);
	if (!temp_array)
		return (NULL);
	
    while (i < len)
	{
		if (i == 0)
		{
			temp_array[i] = ft_calloc(sizeof(char), ft_strlen(example[len - 1]) + 1);
			if (!temp_array[i])
			{
				while (i >= 0)
				{
					free(temp_array[i]);
					i--;
				}
				free(temp_array);
				return (NULL);
			}
			ft_strcpy(temp_array[i], example[len - 1]);
		}
		else
		{
			temp_array[i] = ft_calloc(sizeof(char), ft_strlen(example[i - 1]) + 1);
			if (!temp_array[i])
			{
				while (i >= 0)
				{
					free(temp_array[i]);
					i--;
				}
				free(temp_array);
				return (NULL);
			}
			ft_strcpy(temp_array[i], example[i - 1]);
		}
		i++;
	}
	return (temp_array);
}

// RRa/RRn
void rra_b(char **example)
{
	example = last_to_first(example);
}

// RRR - Does RRa and RRb at the same time 
void rrr(char **example, char **example2)
{
	example = last_to_first(example);
	example2 = last_to_first(example2);
}