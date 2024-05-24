/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:07:07 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/24 15:20:00 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int count = 0;;
	int i = 0;


	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == 9)
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == 9)
			{
				while (argv[1][i] == ' ' || argv[1][i] == 9)
					i++;
				if (argv[1][i] == '\0')
					break ;
				write(1, "   ", 3);
				write(1, &argv[1][i], 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}	
