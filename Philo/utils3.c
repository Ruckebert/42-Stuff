/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:54:17 by aruckenb          #+#    #+#             */
/*   Updated: 2024/10/02 10:06:27 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*temp;

	count = 0;
	temp = (char *)s;
	while (n--)
	{
		temp[count] = '\0';
		count++;
	}
}

static int	overflow(const char *nptr, int minus, long num, int count)
{
	while (*nptr != '\0' && count < 20)
	{
		if (*nptr >= 48 && *nptr <= 57)
			num = num * 10 + *nptr - 48;
		else if (!(*nptr >= 48 && *nptr <= 57))
			return (-1);
		else
			return (num * minus);
		if (*nptr != '0')
			count++;
		nptr++;
	}
	if (count < 20)
		return (num * minus);
	else if (minus == -1)
		return (0);
	else
		return (-1);
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
	while ((*nptr > 8 && *nptr < 14) || (*nptr == ' '))
		nptr++;
	if ((*nptr == '+') || (*nptr == '-'))
	{
		if (*nptr == '-')
			minus = minus * -1;
		nptr++;
	}
	return (overflow(nptr, minus, num, count));
}
