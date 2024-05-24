/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:53:25 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/24 13:05:13 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int n = 0;
    int lookup[256] = {};
    char chara;
    int count = 0;

    if (argc == 3)
    {
        while (argv[1][i])
        {
            j = 0;
            while(argv[2][j])
            {
                if (argv[2][j] == argv[1][i])
                {
					n = i - 1;
                    while (argv[1][n])
                    {
                        if (argv[1][n] == argv[1][i])
                            count++;
                        n--;
					}
                    if (count == 0)
                        write(1, &argv[2][j], 1);
					count = 0;
                    break ;
                }   
                j++;            
            }
            i++;
        }
    }

    write(1, "\n", 1);
    return (0);
}
