/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:46:56 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/24 16:03:12 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int *ft_range(int start, int end)
{
	if (start == 0 || end == 0)
		return (0);

	if (end < 0)
		end *= 1;
	
	int len = abs(start - end);
	int *int_str = malloc(sizeof(int) * end);
	int i = 0;

	while (start <= end)
	{
		int_str[i] = start;
		start++;
		i++;
	}
	return (int_str);
}

int main()
{
	int start = 1;
	int end = 5;
	int i = 0;
	int *num;

	num = ft_range(start, end);

	while (num[i])
	{
		printf("%d", num[i]);
		i++;
	}


}
