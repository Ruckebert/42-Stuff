/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:47:41 by aruckenb          #+#    #+#             */
/*   Updated: 2024/06/13 09:20:48 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	int i = 0;
	int temp = 0;

	if (len == 0)
		return (0);

	while (i < len)
	{
		if (tab[i] > temp)
			temp = tab[i];
		i++;
	}	
	return (temp);
}


//take 2
int max(int *tab, unsigned int len)
{
	int i = 0;
	int temp = 0;

	if (len == 0);
		return (0);
	while (i < len)
	{
		if (tab[i] > temp)
			temp = tab[i];
		i++;
	}
	return (temp);
}

//take 3
int max(int *tab, unsigned int len)
{
	int i = 0;
	int temp = 0;
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > temp)
			temp = tab[i];
		i++;
	}
	return (temp);
}

#include <stdio.h>

int main()
{
	int tab[] = {1, 5, 3, 4};
	int len = 4;
	int num = 0;

	num = max(tab, len);
	printf("%d", num);


}
