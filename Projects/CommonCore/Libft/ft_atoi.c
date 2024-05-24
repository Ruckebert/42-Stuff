/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:27:21 by aruckenb          #+#    #+#             */
/*   Updated: 2024/04/09 09:58:30 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	char	*temp;
	int		num;
	int		minus;

	temp = (char *)nptr;
	num = 0;
	minus = 1;
	while ((*temp > 8 && *temp < 14) || (*temp == ' '))
		temp++;
	if ((*temp == '+') || (*temp == '-'))
	{
		if (*temp == '-')
			minus = minus * -1;
		temp++;
	}
	while (*temp != '\0')
	{
		if (*temp >= 48 && *temp <= 57)
			num = num * 10 + *temp - 48;
		else
			return (num * minus);
		temp++;
	}
	return (num * minus);
}
