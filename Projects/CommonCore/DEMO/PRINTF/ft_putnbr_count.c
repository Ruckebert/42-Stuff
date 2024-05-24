/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:57:23 by aruckenb          #+#    #+#             */
/*   Updated: 2024/04/18 13:36:22 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
		return (nb);
	}
	if (nb == 2147483647)
	{
		write(1, "2147483647", 10);
		return (10);
	}
	if (nb == 0)
	{
		nb = 48;
		write(1, &nb, 1);
		return (0);
	}
	return (nb);
}

static void	write_str(char *str, int count)
{
	count--;
	while (count >= 0)
	{
		write(1, &str[count], 1);
		count--;
	}
}

int	ft_putnbr_count(int nb)
{
	int		store;
	int		count;
	char	character[20];

	count = 0;
	nb = checker(nb);
	if (nb == 0)
		return (nb);
	while (nb > 0)
	{
		store = nb % 10;
		nb = nb / 10;
		character[count] = store + 48;
		count++;
	}
	character[count] = '\0';
	write_str(character, count);
	return (count++);
}