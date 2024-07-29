/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:27:21 by aruckenb          #+#    #+#             */
/*   Updated: 2024/04/15 14:39:35 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_overflow(int minus)
{
	if (minus == 1)
		return (-1);
	else
		return (0);
}

static int	overflow(const char *nptr, int minus, long num, int count)
{
	while (*nptr != '\0' && count < 20)
	{
		if (*nptr >= 48 && *nptr <= 57)
		{
			num = num * 10 + (*nptr - 48);
			if ((minus == 1 && num > 2147483647)
				|| (minus == -1 && - num < -2147483648))
				return (handle_overflow(minus));
		}
		else
			return (num * minus);
		if (*nptr != '0')
			count++;
		nptr++;
	}
	return (num * minus);
}

int	ft_atoi(const char *nptr)
{
	long	num;
	int		minus;
	int		count;

	nptr = (char *)nptr;
	num = 0;
	minus = 1;
	count = 0;
	while ((*nptr > 9 && *nptr < 13) || (*nptr == ' '))
		nptr++;
	if ((*nptr == '+') || (*nptr == '-'))
	{
		if (*nptr == '-')
			minus = minus * -1;
		nptr++;
	}
	return (overflow(nptr, minus, num, count));
}
