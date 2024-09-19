/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:58:22 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/27 11:29:12 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//Handle edge case for letters

int ft_atoi(char *argv)
{
	int i;
	int num;
	int total;

	i = 0;
	while (argv[i])
	{
		num = argv[i] - 48;
		if (i == 0)
			total = num;
		else
			total = (total * 10) + num;
		i++;
	}
	return (total);
}

void ft_putnbr(int num)
{
	if (num > 9)
		ft_putnbr(num / 10);
	num = num % 10;
	num = num + 48;
	write(1, &num, 1);
}

int main(int argc, char **argv)
{
	int num;
	int j = 1;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);	
	}

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		while (j <= 9)
		{
			ft_putnbr(j);
			write(1, " x ", 3);
			ft_putnbr(num);
			write(1, " = ", 3);
			ft_putnbr(num * j);
			write(1, "\n", 1);
			j++;
		}
	}
	return (0);
}
