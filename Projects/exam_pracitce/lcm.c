/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:12:32 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/25 13:21:38 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;

	while (1)
	{
		if (n % a == 0 && n % b == 0)
			break ;
		n++;
	}
	return (n);
}

#include <stdio.h>

int main()
{
	unsigned int a = 8;
	unsigned int b = 5;
	unsigned int c = 0;

	c = lcm(a, b);
	printf("%d", c);
}
