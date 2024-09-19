/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:48:20 by aruckenb          #+#    #+#             */
/*   Updated: 2024/06/13 09:42:57 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int total)
{
	int num = 0;

	num = total % 16;
	if (total > 15)
	{
		total = total / 16;
		ft_putnbr(total);
	}

    if (num < 10)
    {
     	num = num + 48;
        write(1, &num, 1);
    }
    else
	{
		num = num + 87;
		write(1, &num, 1);
	}
}

int main(int argc, char **argv)
{
	int i = 0;
	int num = 0;
	int total = 0;
	
	if (argc == 2)
	{
		while (argv[1][i])
		{
			num = argv[1][i] - 48;
			if (i == 0)
				total = num;
			else
				total = (total * 10) + num; 
			i++;
		}
		ft_putnbr(total);
	}
	write(1, "\n", 1);
	return (0);
}

int main2(int argc, char **argv)
{
	int i = 0;
	int num = 0;
	int total = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			num = argv[1][i] - 48;
			if (i == 0)
				total = num;
			else 
				total = (total * 10) + num;
			i++;
		}
		ft_putnbr(total);
	}
	write(1, "\n", 1);
	return (0);
}
