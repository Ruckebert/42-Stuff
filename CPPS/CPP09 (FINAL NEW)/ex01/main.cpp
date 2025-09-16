/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:59:00 by aruckenb          #+#    #+#             */
/*   Updated: 2025/09/10 11:31:10 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN one;
	if (argc != 2)
		return (0);
	int i = 0;
	while (argv[1][i])
		i++;
	if (i < 5 || isdigit(argv[1][i - 1]))
	{
		std::cerr << "An Error has occured!" << std::endl;
		return (1);
	}
	one.check_value(argv[1]);
}