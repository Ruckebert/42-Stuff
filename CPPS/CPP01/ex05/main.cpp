/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:37:48 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/06 13:47:52 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Please Include A Single Arguement" << std::endl;
		return (1);
	}
	else if (argc > 2)
	{
		std::cout << "Please Only Have A Single Arguement" << std::endl;
		return (1);
	}
	Harl command;
	
	std::cout << "The String you have inputed: " << argv[1] << std::endl;
	std::cout << std::endl;
	command.complain(argv[1]);
}