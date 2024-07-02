/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:32:52 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/25 10:43:33 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int n = 0;

	if (argc == 3)
	{
		while (argv[2][i])
		{
			if (argv[2][i] == argv[1][j])
			{
				j++;
				n = i;
				while (argv[2][n])
				{
					if (argv[2][n] == argv[1][j])
						j++;
					n++;
				}
				if (argv[1][j] == '\0')
				{
					write(1, "1", 1);
				}
				else 
				{
					write(1, "0", 1);
				}
			}
			i++;
		}
	
	}
	write(1, "\n", 1);
	return (0);

}
