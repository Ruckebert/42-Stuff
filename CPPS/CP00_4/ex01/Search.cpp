/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:34:23 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/07 14:17:47 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	CharCheckAndPrint(std::string type)
{
	int i = 0;
	if (type.length() >= 10)
	{
		while (i <= 8)
		{
			std::cout << type[i];
			i++;
		}
		std::cout << "." << " | ";	
	}
	else
	{
		std::cout << std::setw((10 - type.length()) + 1) << std::right;
		i = 0;
		while ((size_t)i <= type.length())
		{
			std::cout << type[i];
			i++;
		}
		std::cout << " | ";
	}
}

void	DisplaySearch(Contact &contacts, int i)
{
	std::cout << "Contact Number:          " << i + 1 << " | ";
	CharCheckAndPrint(contacts.FirstNameGetter());
	CharCheckAndPrint(contacts.LastNameGetter());
	CharCheckAndPrint(contacts.NicknameGetter());
	std::cout << std::endl;
}

int	ValidInput(std::string input, int total)
{
	int i = 0;
	while (input[i])
	{
		if (input[i] >= '0' && input[i] <= '9')
			i++;
		else
			return (1);
	}
	if (input.empty())
		return (1);
	i = std::atoi(input.c_str());
	if (i > total || i < 0 || i == 0)
		return (1);
	return (0);
}

void Search(PhoneBook &book, int i)
{
	int j = 0;
	while (j < i)
	{
		DisplaySearch(*book.GetContact(j), j);
		j++;
	}
	if (j == 0)
		std::cout << "Phonebook is empty! Please add a contact" << std::endl;
	else
	{
		std::string input;
		std::cout << std::endl;
		std::cout << "Please enter the contact number you want to display!" << std::endl;
		std::cout << "Input: " ;
		if (std::cin.peek() == '\n')
		{		
			std::cin.ignore();
			std::cout << "Invalid  Input!" << std::endl;
			return ;
		}
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cerr << "\nError Input!!" << std::endl;
			exit (1) ;
		}
		
		if (ValidInput(input, i) == 1)
		{
			std::cout << std::endl;
			std::cout << "Invalid Contact Number!" << std::endl;
		}
		else
		{
			std::cout << std::endl;
			j = std::atoi(input.c_str());
			DisplayAd(*book.GetContact(j - 1), j - 1);
		}			
	}

}