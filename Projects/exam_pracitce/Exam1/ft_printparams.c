/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:49:51 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/27 10:19:10 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
	}
	num = num % 10;
	num = num + 48;
	write(1, &num, 1);
}


int main(int argc, char **argv)
{
	int j;
	
	j = 0;
	while (j < argc)
	{
		j++;
	}
	ft_putnbr(j - 1);
	write(1, "\n", 1);
	return (0);	
}
