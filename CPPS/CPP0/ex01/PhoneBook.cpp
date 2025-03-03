/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:35:31 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/03 11:41:07 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
	PhoneBook book ;
	int i = 0;
	int k = 0;

	while (1)
	{
		std::string option;
		std::cout << "Please Enter One of the Options Below" << std::endl;
		std::cout << "1: ADD" << std::endl;
		std::cout << "2: SEARCH" << std::endl;
		std::cout << "3: EXIT" << std::endl;
		std::cout << "Input: " ;
		std::cin >> option ;
		if (std::cin.eof())
		{
			std::cerr << "\nError Input!!" << std::endl;
			return (1) ;
		}
	
		if (option.empty() == 1)
			continue ;
		std::cout << std::endl;
		
		if (option.compare("ADD")  == 0)
		{
			Add(book, i, k);
			continue ;
		}
		else if (option.compare("SEARCH")  == 0)
			Search(book, i);
		else if (option.compare("EXIT") == 0)
			return (0);
		std::cout << std::endl;
	}
}
