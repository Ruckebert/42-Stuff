/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:33:18 by aruckenb          #+#    #+#             */
/*   Updated: 2024/06/10 09:52:18 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int res = 0;
	int sign = 0;
	
	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i])
	{
		res *= str_base;
		if (str[i] >= '0' && str[i] <= 9)
			res += str[i] - 48;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 87;
		else if (str[i] >= 'A' && str[i] <= 'F')
            res += str[i] - 55;
		i++;
	}
	return (res * sign);
}*/

int get_char_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f') //Its F because of hex the last digit of hex is F
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int res = 0;
	int sign = 1;
	int value = 0;

	if (str_base > 16 || str_base < 2)
		return (0);
	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
	}
	while (str[i] != '\0')
	{
		value = get_char_value(str[i]);
		if (value < 0 || value >= str_base)
			break ;
		res = res * str_base + value;
		i++;
	}
	return (res * sign);
}

int main()
{
	char *str = "F";
	int num;

	num = ft_atoi_base(str, 16);
	printf("%d", num);
}
