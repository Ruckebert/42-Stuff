/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:26:29 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/25 13:39:13 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int main(int argc, char **argv)
{
	int i = 0;
	char temp;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '_')
			{
				i++;
				temp = argv[1][i];
				if (temp >= 'a' && temp <= 'z')
					temp = temp - 32;
				write(1, &temp, 1);
				i++;
			}
			write(1, &argv[1][i], 1);
			i++;
		
		}
	}
	write(1, "\n", 1);
	return (0);
}
