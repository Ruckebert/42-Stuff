/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:01:51 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/28 11:09:53 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	int answer;

	if (argc == 4)
	{
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[3]);
		if (argv[2][0] == '+')
			printf("%d", num1 + num2);
		if (argv[2][0] == '-')
            printf("%d", num1 - num2);
		if (argv[2][0] == '*')
            printf("%d", num1 * num2);
		if (argv[2][0] == '/')
            printf("%d", num1 / num2);
		if (argv[2][0] == '%')
            printf("%d", num1 % num2);
	}
	write(1, "\n", 1);
	return (0);
}
