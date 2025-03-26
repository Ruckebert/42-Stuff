/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:57:08 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/04 14:28:22 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string brain = "HI THIS IS BRAIN";

	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Normal Stored Values" << std::endl;
	std::cout << brain << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	std::cout << std::endl;
	
	std::cout << "Memory Address Stored Values" << std::endl;
	std::cout << &brain << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << std::endl;
}