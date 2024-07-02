/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:00:12 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/24 14:10:53 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
    int i = 0;
    char temp;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                temp = 122 - argv[1][i] + 97;
                write(1, &temp, 1);
            }
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                temp = 90 - argv[1][i] + 65;
                write(1, &temp, 1);
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
