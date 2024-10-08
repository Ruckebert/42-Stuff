/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:57:23 by aruckenb          #+#    #+#             */
/*   Updated: 2024/04/23 14:46:49 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

void	*ft_memset_printf(void *s, int c, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}

static long int	checker(long int nb)
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
		return (1);
	}
	return (nb);
}

static void	write_str(char *str, int count)
{
	count -= 2;
	while (count >= 0)
	{
		write(1, &str[count], 1);
		count--;
	}
}

int	ft_putnbr_count(long int nb)
{
	int				store;
	int				count;
	char			character[20];

	ft_memset_printf(character, '\0', 20);
	count = nb;
	nb = checker((int)nb);
	if (count == 0 || count == 2147483647 || count == -2147483648)
		return (nb);
	if (count < 0)
		count = 1;
	else
		count = 0;
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
