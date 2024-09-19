/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:37:11 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/27 11:45:07 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int num = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'z'))
			{
				num = argv[1][i] - 97;
				while (0 <= num)
				{
					write(1, &argv[1][i], 1);
					num--;
				}
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				num = argv[1][i] - 65;
                while (0 <= num)
                {
                    write(1, &argv[1][i], 1);
					num--;
                }			
			}
			else 
				write(1, &argv[1][i], 1);
		
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
