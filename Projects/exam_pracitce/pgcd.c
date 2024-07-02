/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:22:23 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/27 10:51:20 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int num;
	int num2;

	if (argc == 3)
	{
		num = atoi(argv[1]);	
		num2 = atoi(argv[2]);
		
		if (num > 0 && num2 > 0)
		{
			while (num != num2)
			{
				if (num > num2)
					num = num - num2;
				else
					num2 = num2 - num;
			}
		}
		printf("%d", num);
	}
	printf("\n");
	return (0);
}
