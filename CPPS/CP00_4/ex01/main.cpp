/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:37:02 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/05 10:37:13 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "phonebook.hpp"

int main()
{
	PhoneBook book ;
	Contact contact;
	int i = 0;
	int k = 0;

	while (std::cin)
	{
		std::string option;
		std::cout << "Please Enter One of the Options Below" << std::endl;
		std::cout << "1: ADD" << std::endl;
		std::cout << "2: SEARCH" << std::endl;
		std::cout << "3: EXIT" << std::endl;
		std::cout << "Input: " ;
		if (std::cin.peek() == '\n')
		{
			std::cin.ignore();
			std::cout << std::endl;
			continue ;
		}
		std::getline(std::cin, option);
		if (std::cin.eof())
		{
			std::cerr << "\nError Input!!" << std::endl;
			return (1) ;
		}
		std::cout << std::endl;
		if (!option.empty())
		{
			if (option.compare("ADD")  == 0)
			{
				Add(book, i, k);
				continue ;
			}
			else if (option.compare("SEARCH")  == 0)
				Search(book, i);
			else if (option.compare("EXIT") == 0)
				return (0);
		}
		std::cout << std::endl;
	}
}