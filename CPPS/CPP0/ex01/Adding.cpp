/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Adding.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:32:08 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/03 16:01:13 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	AddingStr(Contact &contact, int i)
{
	std::string type;
	
	while (1)
	{
		bool invalid = false;
		if (i == 1)
			std::cout << "Please input the first name below" << std::endl;
		else if (i == 2)
			std::cout << "Please input the last name below" << std::endl;
		else if (i == 3)
			std::cout << "Please input the nickname below" << std::endl;
		else if (i == 4)
			std::cout << "Please input their darkest secrets below" << std::endl;
		std::cout << "Input: " ;
		if (std::cin.peek() == '\n')
			std::cin.ignore();
		std::getline(std::cin, type);
		if (std::cin.eof())
		{
			std::cerr << "\nError Input!!" << std::endl;
			exit (1) ;
		}
		if (type.empty())
			std::cout << "Invalid Input!! Try Again" << std::endl;

		int j = 0;
		while (type[j])
		{
			if (!isascii(int(type[j])))
			{
				invalid = true;
				break ;
			}
			j++;
		}

		if (invalid == false)
		{
			if (i == 1)
				contact.FirstNameSetter(type);
			else if (i == 2)
				contact.LastNameSetter(type);
			else if (i == 3)
				contact.NicknameSetter(type);
			else if (i == 4)
				contact.DarkestSetter(type);
			std::cout << std::endl;
			return ;
		}
		std::cout << std::endl;
	}
}

void	AddingPhone(Contact &contact)
{
	std::string check;

	while (1)
	{
		std::cout << "Please input the phone number below" << std::endl;
		std::cout << "Input: " ;
		if (std::cin.peek() == '\n')
			std::cin.ignore();
		std::getline(std::cin, check);
		if (std::cin.eof())
		{
			std::cerr << "\nError Input!!" << std::endl;
			exit (1) ;
		}

		int i = 0;
		bool isnumber = true;
		while (check[i])
		{
			if (check[i] >= '0' && check[i] <= '9')
				i++;
			else
			{
				isnumber = false;
				break ;
			}
		}
		if (isnumber == false)
			std::cout << "Please only enter numbers!" << std::endl;
		else
		{
			if (check.length() > 10)
				std::cout << "Invalid Phone Number!! Try Again" << std::endl;
			else
			{
				long type = std::stol(check);
				contact.PhoneNumberSetter(type);
				std::cout << std::endl;
				return ;
			}
		}
		std::cout << std::endl;
	}
}

void	Adding(Contact &contacts)
{
	AddingStr(contacts, 1);
	AddingStr(contacts, 2);
	AddingStr(contacts, 3);
	AddingPhone(contacts);
	AddingStr(contacts, 4);
}

void	DisplayAd(Contact &contacts, int i)
{
	std::cout << "Displaying Contact Number " << i + 1 << std::endl;
	std::cout << "First Name: " << contacts.FirstNameGetter() << std::endl;
	std::cout << "Last Name: " << contacts.LastNameGetter() << std::endl;
	std::cout << "Nickname: " << contacts.NicknameGetter() << std::endl;
	std::cout << "Phonenumber: " << contacts.PhoneNumberGetter() << std::endl;
	std::cout << "Darkest Secret: " << contacts.DarkestGetter() << std::endl;
	std::cout << std::endl;
}

void Add(PhoneBook &book, int &i, int &k)
{
	if (i == 8)
	{
		if (k == 8)
			k = 0;
		std::cout << "Phonebook full!!" << std::endl;
		std::cout << "Replacing Oldest Element!" << std::endl;
		i = k;
		Adding(book.contacts[i]);
		DisplayAd(book.contacts[i], i);
		i = 8;
		k++;
	}
	else
	{
		Adding(book.contacts[i]);
		DisplayAd(book.contacts[i], i);
		i++;
	}
	
}